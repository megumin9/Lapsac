#include "clang/AST/DeclTemplate.h"
#include "clang/Driver/DriverDiagnostic.h"
#include "clang/StaticAnalyzer/Checkers/BuiltinCheckerRegistration.h"
#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CallDescription.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CallEvent.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/DynamicType.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/ProgramStateTrait.h"
#include "llvm/ADT/ImmutableList.h"
#include <vector>
#include <regex>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <unistd.h>
#include <cstring> 
#include <chrono>

using namespace clang;
using namespace ento;
using namespace std;




typedef std::pair<int, std::vector<SVal>> ArgsType;
typedef std::pair<std::string, ArgsType> FuncCaseType;
typedef std::pair<std::pair<FuncCaseType,SVal>,std::vector<size_t>> FuncSumType;

struct Road {
  private:
    size_t number;
    Road(size_t num) :number(num) {};

  public: 

    static Road Init(size_t num){
      return Road(num);
    }
  
    size_t getNumber() const {
      return number;
    }

    bool operator==(const Road &X) const {
      return number == X.number;
    }

     bool operator!=(const Road &X) const {
      return number != X.number;
    }
    void Profile(llvm::FoldingSetNodeID &ID) const {
      ID.AddInteger(number);
    }
};
using TestType = CLANG_ENTO_PROGRAMSTATE_MAP(size_t,Road);

struct TestMap{};

template <>
struct clang::ento::ProgramStateTrait<TestMap> : public clang::ento::ProgramStatePartialTrait<TestType> {
  static void *GDMIndex() {
    static int Index;
    return &Index;
  }
};

std::vector<FuncSumType> FuncSumList;
std::vector<std::pair<std::pair<const MemRegion*,const MemRegion*>,std::vector<size_t>>> SameLazyFuncList;
std::vector<std::pair<std::pair<SVal, SVal>,std::vector<size_t>>> SameSValList;
static std::chrono::_V2::steady_clock::time_point start_time;




std::string file_path = __FILE__;
size_t last_slash_pos = file_path.find_last_of('/');
std::string dir_path = file_path.substr(0, last_slash_pos);
std::string project_cmp_list_path = dir_path + "/ProjectCmpList.txt";
unsigned LoopCount = 0;




namespace{

class FunctionSummary
  : public Checker<check::PostCall,
    check::PreStmt<CallExpr>,
    check::PreStmt<BinaryOperator>,
    check::EndAnalysis,
    eval::Call>{
  
public:
  void checkPostCall(const CallEvent &Call, CheckerContext &C) const;
  void checkPreStmt(const BinaryOperator *BO, CheckerContext &C) const;
  void checkPreStmt(const CallExpr *CE, CheckerContext &C) const;
  void checkEndAnalysis(ExplodedGraph &G, BugReporter &BR, ExprEngine &Eng) const;
  bool evalCall(const CallEvent &Call, CheckerContext &C) const;
};

}

std::vector<size_t> GetNowRoad(ProgramStateRef State){
  size_t i = 0;
  std::vector<size_t> NowRoad;
  while (auto It=State->get<TestMap>(i)){
    NowRoad.push_back(It->getNumber());
    i = i + 1;
  }
  return NowRoad;
}

bool IsSameRoad(std::vector<size_t> road1, std::vector<size_t> road2){
  if (road1.size()>road2.size())
    return false;
  for (size_t i = 0; i<road1.size();++i){
    if (road1[i] != road2[i])
      return false;
  }
  return true;
}

//第三方库这是一个问题==
bool IsCompareListFunction(string FunctionName)
{
  std::ifstream file(project_cmp_list_path);  
  std::string line;
  while (std::getline(file, line)) {  
    if (line == FunctionName) {  
      file.close(); 
      return true;
    }
  }
  file.close();  
  return false;
}

bool IsCompareFunction(string FunctionName)
{

  if (IsCompareListFunction(FunctionName))
    return true;
  
  std::transform(FunctionName.begin(), FunctionName.end(), FunctionName.begin(), ::tolower);

  if (FunctionName.find("cmp") != std::string::npos || FunctionName.find("comp") != std::string::npos || FunctionName.find("less") != std::string::npos || FunctionName.find("greater") != std::string::npos)
    return true;
  return false;
}

bool IsSameVal(SVal Val1, SVal Val2, ProgramStateRef State, SValBuilder &SVB){
  if (Val1 == Val2)
    return true;

  std::string Val1Str_ttt;
  std::string Val2Str_ttt;
  llvm::raw_string_ostream rso1_ttt(Val1Str_ttt);
  Val1.dumpToStream(rso1_ttt);
  rso1_ttt.flush();
  llvm::raw_string_ostream rso2_ttt(Val2Str_ttt);
  Val2.dumpToStream(rso2_ttt);
  rso2_ttt.flush();

  if (Val1Str_ttt == Val2Str_ttt) 
    return true;
  

  std::vector<size_t> nowroad = GetNowRoad(State);

  for (auto It : SameSValList) {
    if (IsSameRoad(It.second,nowroad))
      if (std::make_pair(Val1, Val2) == It.first) {
        return true;
      }
  }

  if (auto Val1Region = Val1.getAsRegion())
    if (auto Val2Region = Val2.getAsRegion())
      for (auto It : SameLazyFuncList) {
        if (IsSameRoad(It.second,nowroad))
          if (std::make_pair(Val1Region,Val2Region) == It.first) {
            return true;
          }
      }

  //常数处理
  
  if (isa<NonLoc>(Val1) && isa<NonLoc>(Val2)) {
    SVal EqualSVal = SVB.evalBinOpNN(State, BO_EQ, Val1.castAs<NonLoc>(), Val2.castAs<NonLoc>(), SVB.getContext().IntTy);
    ProgramStateRef NotEqual;
    if (isa<NonLoc>(EqualSVal)) {
      NotEqual = State->assume(EqualSVal.castAs<NonLoc>(),false);
      if (!NotEqual)
        return true;
    }
  }

  //类处理
  std::string Val1Str_seki;
  std::string Val2Str_seki;
  llvm::raw_string_ostream rso1_seki(Val1Str_seki);
  Val1.dumpToStream(rso1_seki);
  rso1_seki.flush();
  llvm::raw_string_ostream rso2_seki(Val2Str_seki);
  Val2.dumpToStream(rso2_seki);
  rso2_seki.flush();


  if (Val1Str_seki.find("derived") != std::string::npos && Val2Str_seki.find("derived") != std::string::npos){ 
    std::regex pattern(R"(Element\{([^{}]*(?:\{[^{}]*\}[^{}]*)*)\}.([a-zA-Z_][a-zA-Z0-9_]*))");
    std::smatch match;
    if (std::regex_search(Val1Str_seki, match, pattern)) {
      Val1Str_seki = match.str(0);
    } 

    if (std::regex_search(Val2Str_seki, match, pattern)) {
      Val2Str_seki = match.str(0);
    }  

    if (Val1Str_seki == Val2Str_seki)
      return true;

    for (auto It : SameSValList) {
      if (IsSameRoad(It.second,nowroad)) {
        std::string FirstStr;
        std::string SecondStr;
        llvm::raw_string_ostream rsox(FirstStr);
        It.first.first.dumpToStream(rsox);
        rsox.flush();
        llvm::raw_string_ostream rsoy(SecondStr);
        It.first.second.dumpToStream(rsoy);
        rsoy.flush();
        if (FirstStr.find("derived") != std::string::npos && SecondStr.find("derived") != std::string::npos)
          if (FirstStr.find(Val1Str_seki) != std::string::npos && SecondStr.find(Val2Str_seki) != std::string::npos)
            return true;
      }
    }
    return false;
  }


  //指针处理
  std::string Val1Str;
  std::string Val2Str;
  llvm::raw_string_ostream rso1(Val1Str);
  Val1.dumpToStream(rso1);
  rso1.flush();
  llvm::raw_string_ostream rso2(Val2Str);
  Val2.dumpToStream(rso2);
  rso2.flush();

  if (Val1Str.find("SymRegion") != std::string::npos && Val2Str.find("SymRegion") != std::string::npos){ 
  
    std::regex pattern(R"(SymRegion\{([^{}]*(?:\{[^{}]*\}[^{}]*)*)\})");
    std::smatch match;
    if (std::regex_search(Val1Str, match, pattern)) {
      Val1Str = '&' + match.str(0);
    } 

    if (std::regex_search(Val2Str, match, pattern)) {
      Val2Str = '&' + match.str(0);
    }  

    if (Val1Str == Val2Str)
      return true;
  
    for (auto It : SameSValList) {
      if (IsSameRoad(It.second,nowroad)) {
        std::string FirstStr;
        std::string SecondStr;
        llvm::raw_string_ostream rsox(FirstStr);
        It.first.first.dumpToStream(rsox);
        rsox.flush();
        llvm::raw_string_ostream rsoy(SecondStr);
        It.first.second.dumpToStream(rsoy);
        rsoy.flush();
        if ((Val1Str == FirstStr) && (Val2Str == SecondStr))
          return true;
      } 
    }

    return false;

  }

  return false;

}

void updateSValList(ProgramStateRef State, SValBuilder &SVB){
  bool nochange = false;
  auto nowroad = GetNowRoad(State);
  while (!nochange){
    nochange = true;

    for (auto It1: SameSValList){
      for (auto It2: SameSValList){
        if (IsSameRoad(It1.second,It2.second) && IsSameRoad(It2.second,nowroad)){
          if (IsSameVal(It1.first.second,It2.first.first,State,SVB) && !IsSameVal(It1.first.first,It2.first.second,State,SVB)){
            SameSValList.push_back(std::make_pair(std::make_pair(It1.first.first,It2.first.second),It2.second));
            SameSValList.push_back(std::make_pair(std::make_pair(It2.first.second,It1.first.first),It2.second));
            nochange = false;
            break;
          }
        }
      }
      if (!nochange)
        break;
    }
  }
}

void updateLazyFuncList(ProgramStateRef State, SValBuilder &SVB){
  bool nochange = false;
  std::vector<size_t> nowroad = GetNowRoad(State);
  while (!nochange){
    nochange = true;
    for (auto It1: SameLazyFuncList){
      for (auto It2: SameLazyFuncList){
        if (IsSameRoad(It1.second,It2.second) && IsSameRoad(It2.second,nowroad)){
          if ((It1.first.second == It2.first.first) && (It1.first.first != It2.first.second)){
            SameLazyFuncList.push_back(std::make_pair(std::make_pair(It1.first.first,It2.first.second),It2.second));
            SameLazyFuncList.push_back(std::make_pair(std::make_pair(It2.first.second,It1.first.first),It2.second));
            nochange = false;
            break;
          }
        }
      }
      if (!nochange)
        break;
    }
  }
}

bool IsSameFunction(FuncCaseType Func1, FuncCaseType Func2, ProgramStateRef State, SValBuilder &SVB){
  if (Func1.first != Func2.first)
    return false;
  if (Func1.second.first != Func2.second.first)
    return false;
    
  int Argsnum = Func1.second.first; 
  for (int i = 0; i<Argsnum; i++) {
    //全局int变量？
    if (!IsSameVal(Func1.second.second[i],Func2.second.second[i], State, SVB))
      return false;
  }
  return true;
}

bool IsPartExchangeFunction(FuncCaseType Func1, FuncCaseType Func2, ProgramStateRef State, SValBuilder &SVB){
  
    if (Func1.first != Func2.first)
      return false;
    if (Func1.second.first != Func2.second.first)
      return false;
    
    int Argsnum = Func1.second.first; 
    for (int i = 0; i<Argsnum/2; i++) {
      if (!IsSameVal(Func1.second.second[i+Argsnum/2],Func2.second.second[i], State, SVB))
        return false;
    }

    return true;

}

bool IsExchangeFunction(FuncCaseType Func1, FuncCaseType Func2, ProgramStateRef State, SValBuilder &SVB){
  
    if (Func1.first != Func2.first)
      return false;
    if (Func1.second.first != Func2.second.first)
      return false;
    
    int Argsnum = Func1.second.first; 
    for (int i = 0; i<Argsnum/2; i++) {
      if (!IsSameVal(Func1.second.second[i],Func2.second.second[i+Argsnum/2], State, SVB))
        return false;
      if (!IsSameVal(Func1.second.second[i+Argsnum/2],Func2.second.second[i], State, SVB))
        return false;
    }

    return true;

}

bool IsCircleFunction(FuncCaseType Func1, FuncCaseType Func2, FuncCaseType Func3, ProgramStateRef State, SValBuilder &SVB){
  if (Func1.first != Func2.first)
    return false;
  
  if (Func2.first != Func3.first)
    return false;
    
  if (Func1.second.first != Func2.second.first)
    return false;

  if (Func2.second.first != Func3.second.first)
    return false;

  int Argsnum = Func1.second.first; 
  for (int i = 0; i<Argsnum/2; i++) {
    if (!IsSameVal(Func1.second.second[i],Func3.second.second[i+Argsnum/2], State, SVB))
      return false;
    if (!IsSameVal(Func2.second.second[i],Func1.second.second[i+Argsnum/2], State, SVB))
      return false;
    if (!IsSameVal(Func3.second.second[i],Func2.second.second[i+Argsnum/2], State, SVB))
      return false;
  }
  return true;
}

bool IsTransiveFunction(FuncCaseType Func1, FuncCaseType Func2, FuncCaseType Func3, ProgramStateRef State, SValBuilder &SVB){
  if (Func1.first != Func2.first)
    return false;
  
  if (Func2.first != Func3.first)
    return false;
    
  if (Func1.second.first != Func2.second.first)
    return false;

  if (Func2.second.first != Func3.second.first)
    return false;

  int Argsnum = Func1.second.first; 
  for (int i = 0; i<Argsnum/2; i++) {
    if (!IsSameVal(Func1.second.second[i],Func3.second.second[i], State, SVB))
      return false;
    if (!IsSameVal(Func2.second.second[i],Func1.second.second[i+Argsnum/2], State, SVB))
      return false;
    if (!IsSameVal(Func3.second.second[i+Argsnum/2],Func2.second.second[i+Argsnum/2], State, SVB))
      return false;
  }

  return true;
}


void FunctionSummary::checkPreStmt(const CallExpr *CE, CheckerContext &C) const{
  if (const FunctionDecl *FD = CE->getDirectCallee()) {
    if (FD->getNameAsString() == "NewTest") {
      start_time = std::chrono::steady_clock::now(); // ← 开始计时
      llvm::errs() << "NewTest: \n";
      FuncSumList.clear();
      SameSValList.clear();
      SameLazyFuncList.clear();
    }
  }

  auto Now = std::chrono::steady_clock::now();
  auto ElapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(Now - start_time).count();
  llvm::errs() << "NowTime: " << ElapsedSeconds <<"\n";;
  if (ElapsedSeconds >= 240) {
    llvm::errs() << "TimeLimit\n";
    auto *Sink = C.generateSink(C.getState(), C.getPredecessor());
    if (Sink)
      return;
  }
  
}

bool FunctionSummary::evalCall(const CallEvent &Call, CheckerContext &C) const{

  const auto *Func = dyn_cast_or_null<FunctionDecl>(Call.getDecl());


  if (!Func)
    return false;
  const IdentifierInfo *II = Call.getCalleeIdentifier();  
  if(!II)
    return false;

  ProgramStateRef State = C.getState();
  SValBuilder &SVB = C.getSValBuilder();
  
  QualType RetType = Call.getResultType();
  SVal ThisRet;
   
  llvm::errs() << "\n";

  string FunctionName(II->getName().data(),II->getName().size());
  

  const LocationContext *LCtx = C.getLocationContext();
  if (const FunctionDecl *FD = dyn_cast_or_null<FunctionDecl>(LCtx->getDecl())) {
    string CurFunction = FD->getNameAsString();
    if (CurFunction == "test1" || CurFunction == "test3_1" || CurFunction == "test3_2" || CurFunction == "test2" || CurFunction == "test4"){
      return false;
    }
  }

  size_t i = 0;
  llvm::errs() << "The Road is: x";
  std::vector<size_t> nowroad;
  while (auto It=State->get<TestMap>(i)){
    llvm::errs() << It->getNumber();
    nowroad.push_back(It->getNumber());
    i = i + 1;
  }

  llvm::errs() << "\n";

  int num = Call.getNumArgs();
  std::vector<SVal> Args;
  for (int i = 0; i<num; i++) 
  {
    Args.push_back(Call.getArgSVal(i));
  }
  
  const auto *InstCall = dyn_cast<CXXInstanceCall>(&Call);
  if (InstCall) {
    num ++;
    Args.insert(Args.begin(),InstCall->getCXXThisVal());
  }

  FuncCaseType ThisFunc = std::make_pair(FunctionName, std::make_pair(num,Args));

  if (!IsCompareFunction(FunctionName))
    return false;
  

  if (RetType->isIntegerType()) {
    ThisRet = SVB.conjureSymbolVal(nullptr, Call.getOriginExpr(), C.getLocationContext(), RetType, 0);
    State = State->BindExpr(Call.getOriginExpr(),C.getLocationContext(),ThisRet);
  } else if (RetType->isBooleanType()) {
    ThisRet = SVB.conjureSymbolVal(nullptr, Call.getOriginExpr(), C.getLocationContext(), RetType, 0);
    State = State->BindExpr(Call.getOriginExpr(),C.getLocationContext(),ThisRet);
  } else {
    return false;
  }
  
  //相同函数返回相同
  bool HasSame = false;
  FuncSumType SameFunc;
  for (auto It:FuncSumList){
    if (IsSameRoad(It.second,nowroad))
      if (IsSameFunction(It.first.first,ThisFunc,State,SVB)){
        HasSame = true;
        SameFunc = It;
        break;
      }
  }

  if (HasSame){
    SVal SameRet = SameFunc.first.second;
    
    if (!(ThisRet.getAs<nonloc::ConcreteInt>() && SameRet.getAs<nonloc::ConcreteInt>())) {
      if (auto ThisLoc = ThisRet.getAs<Loc>()){    
        SameSValList.push_back(std::make_pair(std::make_pair(SameRet,ThisRet),nowroad));
        SameSValList.push_back(std::make_pair(std::make_pair(ThisRet,SameRet),nowroad));
        updateSValList(State,SVB);
      } else if (auto ThisLazy = ThisRet.getAs<clang::ento::nonloc::LazyCompoundVal>()){
        const MemRegion *ThisRegion = ThisLazy->getRegion();
        auto SameLazy = SameRet.getAs<clang::ento::nonloc::LazyCompoundVal>();
        const MemRegion *SameRegion = SameLazy->getRegion();
        SameLazyFuncList.push_back(std::make_pair(std::make_pair(SameRegion,ThisRegion),nowroad));
        SameLazyFuncList.push_back(std::make_pair(std::make_pair(ThisRegion,SameRegion),nowroad));
        updateLazyFuncList(State,SVB);
      } else { 
        QualType ThisType = ThisRet.getType(C.getASTContext());
        if (!ThisType.isNull() && ThisType->isIntegerType()){
          SVal EqualSVal = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), SameRet.castAs<NonLoc>(), SVB.getContext().IntTy);
          ProgramStateRef EqualState = State->assume(EqualSVal.castAs<NonLoc>(), true); 

          if (EqualState) {
            State = EqualState;
          }
        }
        SameSValList.push_back(std::make_pair(std::make_pair(SameRet,ThisRet),nowroad));
        SameSValList.push_back(std::make_pair(std::make_pair(ThisRet,SameRet),nowroad));
        updateSValList(State,SVB);
      }
      State = State->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SameRet);
      C.addTransition(State);
      return true;
    }
  }

  //反自反性

  if (IsExchangeFunction(ThisFunc,ThisFunc, State, SVB) && ThisRet.getAs<NonLoc>()){
    QualType RetType = ThisRet.getType(C.getASTContext());
    if (RetType == C.getASTContext().BoolTy){
      ProgramStateRef StateFalse = State->assume(ThisRet.castAs<NonLoc>(), false);

      if (StateFalse) {
        StateFalse = StateFalse->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeTruthVal(false));
        State = StateFalse;
      }
    }
    else if (RetType == C.getASTContext().IntTy){
      SVal Zero = SVB.makeIntVal(0,SVB.getContext().IntTy);

      SVal ThisRetEqualZero = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      ProgramStateRef StateTrue = State->assume(ThisRetEqualZero.castAs<NonLoc>(), true); 

      if (StateTrue) {
        StateTrue = StateTrue->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(0,Call.getResultType()));
        State = StateTrue;
      }
    }
    C.addTransition(State);
    return true;
  }

  //反对称性
  bool HasExchangeFunc = false;
  FuncSumType ExchangeFunc;
  for (auto It : FuncSumList){
    if (IsSameRoad(It.second,nowroad))
      if (IsExchangeFunction(It.first.first,ThisFunc,State,SVB)) {
        HasExchangeFunc = true;
        ExchangeFunc = It;
        break;
      }
  }

  if (HasExchangeFunc && ThisRet.getAs<NonLoc>()){
    SVal ExRet = ExchangeFunc.first.second;

    QualType RetType = ThisRet.getType(C.getASTContext());
    if (RetType == C.getASTContext().BoolTy){
      ProgramStateRef State1 = State->assume(ExRet.castAs<NonLoc>(), true);
      if (State1) {
        ProgramStateRef State2 = State1->assume(ThisRet.castAs<NonLoc>(), false);
  
        if (State2) {
          State2 = State2->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeTruthVal(false));
          State = State2;
          C.addTransition(State);
          return true;
        }     
      }
    }
    else if (RetType == C.getASTContext().IntTy){
      SVal Zero = SVB.makeIntVal(0, SVB.getContext().IntTy);

      SVal ThisRetLessThanZero = SVB.evalBinOpNN(State, BO_LT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);


      SVal ExRetLessThanZero = SVB.evalBinOpNN(State, BO_LT, ExRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ExRetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, ExRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);


      ProgramStateRef State1 = State->assume(ExRetLessThanZero.castAs<NonLoc>(), true);
      if (State1){
        ProgramStateRef State1_ThisGt = State1->assume(ThisRetGreaterThanZero.castAs<NonLoc>(), true);
        State1_ThisGt = State1_ThisGt->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(1,Call.getResultType()));
        State = State1_ThisGt;
        C.addTransition(State);
        return true;
      }

      ProgramStateRef State2 = State->assume(ExRetGreaterThanZero.castAs<NonLoc>(), true);
      if (State2){
        ProgramStateRef State2_ThisLt = State2->assume(ThisRetLessThanZero.castAs<NonLoc>(), true);
        State2_ThisLt = State2_ThisLt->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(-1,Call.getResultType()));
        State = State2_ThisLt;
        C.addTransition(State);
        return true;
      }
    }
  }

  //传递性

  bool HasCircleFunc = false;
  FuncSumType CircleFunc1, CircleFunc2;
  for (auto It1 : FuncSumList){ 
    for (auto It2 : FuncSumList){   
      if (IsSameRoad(It1.second,It2.second) && IsSameRoad(It2.second,nowroad))
        if (IsCircleFunction(It1.first.first,It2.first.first,ThisFunc,State,SVB)) {
          HasCircleFunc = true;
          CircleFunc1 = It1;
          CircleFunc2 = It2;
          break;
        }
    }
  }

  if (HasCircleFunc && ThisRet.getAs<NonLoc>()){
    SVal Func1Ret = CircleFunc1.first.second;
    SVal Func2Ret = CircleFunc2.first.second;

    QualType RetType = ThisRet.getType(C.getASTContext());
    if (RetType == C.getASTContext().BoolTy){
      ProgramStateRef State1 = State->assume(Func1Ret.castAs<NonLoc>(), true);
      if (State1){
        ProgramStateRef State2 = State1->assume(Func2Ret.castAs<NonLoc>(), true);
      
        if (State2){
          ProgramStateRef State3 = State2->assume(ThisRet.castAs<NonLoc>(), false);
          if (State3){
            State3 = State3->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeTruthVal(false));
            State = State3;
            C.addTransition(State);
            return true;
          }
        }
      }
    }
    else if (RetType == C.getASTContext().IntTy){
      SVal Zero = SVB.makeIntVal(0,SVB.getContext().IntTy);

      SVal Func1RetLessThanZero = SVB.evalBinOpNN(State, BO_LT, Func1Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal Func2RetLessThanZero = SVB.evalBinOpNN(State, BO_LT, Func2Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      ProgramStateRef State1 = State->assume(Func1RetLessThanZero.castAs<NonLoc>(), true); 
      if (State1){
        ProgramStateRef State2 = State1->assume(Func2RetLessThanZero.castAs<NonLoc>(), true); 
        if (State2){
          ProgramStateRef State3 = State2->assume(ThisRetGreaterThanZero.castAs<NonLoc>(), true); 
          if (State3){
            State3 = State3->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(1,Call.getResultType()));
            State = State3;
            C.addTransition(State);
            return true;
          }
        }
      }

      SVal Func1RetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, Func1Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal Func2RetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, Func2Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetLessThanZero = SVB.evalBinOpNN(State, BO_LT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      State1 = State->assume(Func1RetGreaterThanZero.castAs<NonLoc>(), true); 
      if (State1){
        ProgramStateRef State2 = State1->assume(Func2RetGreaterThanZero.castAs<NonLoc>(), true); 
        if (State2){
          ProgramStateRef State3 = State2->assume(ThisRetLessThanZero.castAs<NonLoc>(), true); 
          if (State3){
            State3 = State3->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(-1,Call.getResultType()));
            State = State3;
            C.addTransition(State);
            return true;
          }
        }
      }
    }
  }

  //一致性

  bool HasTransiveFunc = false;
  FuncSumType TransiveFunc1, TransiveFunc2;
  for (auto It1 : FuncSumList){ 
    for (auto It2 : FuncSumList){   
      if (IsSameRoad(It1.second,It2.second) && IsSameRoad(It2.second,nowroad))
        if (IsTransiveFunction(It1.first.first,It2.first.first,ThisFunc,State,SVB)) {
          HasTransiveFunc = true;
          TransiveFunc1 = It1;
          TransiveFunc2 = It2;
          break;
        }
    }
  }

  if (HasTransiveFunc && ThisRet.getAs<NonLoc>()){
    SVal Func1Ret = TransiveFunc1.first.second;
    SVal Func2Ret = TransiveFunc2.first.second;

    QualType RetType = ThisRet.getType(C.getASTContext());
    if (RetType == C.getASTContext().BoolTy){
      ProgramStateRef State1 = State->assume(Func1Ret.castAs<NonLoc>(), false);
      if (State1){
        ProgramStateRef State2 = State1->assume(Func2Ret.castAs<NonLoc>(), false);
        if (State2){
          ProgramStateRef State3 = State2->assume(ThisRet.castAs<NonLoc>(), false);
          if (State3){
            State3 = State3->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeTruthVal(false));
            State = State3;
            C.addTransition(State);
            return true;
          }
        }
      }
    }
    else if (RetType == C.getASTContext().IntTy)
    {
      SVal Zero = SVB.makeIntVal(0,SVB.getContext().IntTy);

      SVal Func1EqualZero = SVB.evalBinOpNN(State, BO_EQ, Func1Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal Func2RetEqualZero = SVB.evalBinOpNN(State, BO_EQ, Func2Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetEqualZero = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      ProgramStateRef State1 = State->assume(Func1EqualZero.castAs<NonLoc>(), true); 
      if (State1){
        ProgramStateRef State2 = State1->assume(Func2RetEqualZero.castAs<NonLoc>(), true); 
        if (State2){
          ProgramStateRef State3 = State2->assume(ThisRetEqualZero.castAs<NonLoc>(), true); 
          if (State3){
            State3 = State3->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(0,Call.getResultType()));
            State = State3;
            C.addTransition(State);
            return true;
          }
        }
      }

      SVal Func1RetLessThanZero = SVB.evalBinOpNN(State, BO_LT, Func1Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal Func2RetLessThanZero = SVB.evalBinOpNN(State, BO_LT, Func2Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetLessThanZero = SVB.evalBinOpNN(State, BO_LT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      State1 = State->assume(Func1RetLessThanZero.castAs<NonLoc>(), false); 
      if (State1){
        ProgramStateRef State2 = State1->assume(Func2RetLessThanZero.castAs<NonLoc>(), false); 
        if (State2){
          ProgramStateRef State3 = State2->assume(ThisRetLessThanZero.castAs<NonLoc>(), false); 
          if (State3){
            State3 = State3->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(1,Call.getResultType()));
            State = State3;
            C.addTransition(State);
            return true;
          }
        }
      }
      SVal Func1RetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, Func1Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal Func2RetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, Func2Ret.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      State1 = State->assume(Func1RetGreaterThanZero.castAs<NonLoc>(), false); 
      if (State1){
        ProgramStateRef State2 = State1->assume(Func2RetGreaterThanZero.castAs<NonLoc>(), false); 
        if (State2){
          ProgramStateRef State3 = State2->assume(ThisRetGreaterThanZero.castAs<NonLoc>(), false); 
          if (State3){
            State3 = State3->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(-1,Call.getResultType()));
            State = State3;
            C.addTransition(State);
            return true;
          }
        }
      }
    }
  } 

  //都不符合开始分支
  if (ThisRet.getAs<NonLoc>()){
    QualType RetType = ThisRet.getType(C.getASTContext());
    if (RetType == C.getASTContext().BoolTy){
      ProgramStateRef CanBeFalse, CanBeTrue;
      CanBeFalse = State->assume(ThisRet.castAs<NonLoc>(), false);
      CanBeTrue = State->assume(ThisRet.castAs<NonLoc>(), true);
      if (CanBeFalse){
        CanBeFalse = CanBeFalse->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeTruthVal(false));
        Road road = Road::Init(0);
        size_t i = 0;
        while (CanBeFalse->get<TestMap>(i)) {
          i = i + 1;
        }
        CanBeFalse = CanBeFalse->set<TestMap>(i,road);
        C.addTransition(CanBeFalse);
      }

      if (CanBeTrue){
        CanBeTrue = CanBeTrue->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeTruthVal(true));
        Road road = Road::Init(1);
        size_t i = 0;
        while (CanBeTrue->get<TestMap>(i)) {
          i = i + 1;
        }
        CanBeTrue = CanBeTrue->set<TestMap>(i,road);
        C.addTransition(CanBeTrue);
      }

      return true;
    }else if (RetType == C.getASTContext().IntTy){
      ProgramStateRef LessThanZero, EqualZero, GreaterThanZero;
      SVal Zero = SVB.makeIntVal(0,SVB.getContext().IntTy);
      
      SVal ThisRetLessThanZero = SVB.evalBinOpNN(State, BO_LT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetEqualZero = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      LessThanZero = State->assume(ThisRetLessThanZero.castAs<NonLoc>(), true); 
      EqualZero = State->assume(ThisRetEqualZero.castAs<NonLoc>(), true);
      GreaterThanZero = State->assume(ThisRetGreaterThanZero.castAs<NonLoc>(), true);

      if (LessThanZero){
        Road road = Road::Init(0);
        size_t i = 0;
        while (LessThanZero->get<TestMap>(i)) {
          i = i + 1;
        }
        llvm::errs() << "The road length:"<<i<<"\n";
        LessThanZero = LessThanZero->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(-1,Call.getResultType()));
        LessThanZero = LessThanZero->set<TestMap>(i,road);
        C.addTransition(LessThanZero);
      }

      if (EqualZero){
        Road road = Road::Init(2);
        size_t i = 0;
        while (EqualZero->get<TestMap>(i)) {
          i = i + 1;
        }
        llvm::errs() << "The road length:"<<i<<"\n";
        EqualZero = EqualZero->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(0,Call.getResultType()));
        EqualZero = EqualZero->set<TestMap>(i,road);
        C.addTransition(EqualZero);
      }

      if (GreaterThanZero){
        Road road = Road::Init(1);
        size_t i = 0;
        while (GreaterThanZero->get<TestMap>(i)) {
          i = i + 1;
        }
        llvm::errs() << "The road length:"<<i<<"\n";
        GreaterThanZero = GreaterThanZero->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SVB.makeIntVal(1,Call.getResultType()));
        GreaterThanZero = GreaterThanZero->set<TestMap>(i,road);
        C.addTransition(GreaterThanZero);
      }

      return true;
    }
    
  }
  return false;
}


void FunctionSummary::checkPostCall(const CallEvent &Call, CheckerContext &C) const{
  const auto *Func = dyn_cast_or_null<FunctionDecl>(Call.getDecl());

  
  if (!Func)
    return;
  const IdentifierInfo *II = Call.getCalleeIdentifier();  
  if(!II)
    return;

  

  ProgramStateRef State = C.getState();
  SValBuilder &SVB = C.getSValBuilder();

  SVal ThisRet = Call.getReturnValue();

  
    
  llvm::errs() << "\n";

  string FunctionName(II->getName().data(),II->getName().size());
  

  const LocationContext *LCtx = C.getLocationContext();
  if (const FunctionDecl *FD = dyn_cast_or_null<FunctionDecl>(LCtx->getDecl())) {
    string CurFunction = FD->getNameAsString();
    if (CurFunction == "test1" || CurFunction == "test3_1" || CurFunction == "test3_2" || CurFunction == "test2" || CurFunction == "test4"){
      return;
    }
  }

  size_t i = 0;
  llvm::errs() << "The Road is: x";
  std::vector<size_t> nowroad;
  while (auto It=State->get<TestMap>(i)){
    llvm::errs() << It->getNumber();
    nowroad.push_back(It->getNumber());
    i = i + 1;
  }

  llvm::errs() << "\n";

  int num = Call.getNumArgs();
  std::vector<SVal> Args;
  for (int i = 0; i<num; i++) 
  {
    Args.push_back(Call.getArgSVal(i));
  }
  
  const auto *InstCall = dyn_cast<CXXInstanceCall>(&Call);
  if (InstCall) {
    num ++;
    Args.insert(Args.begin(),InstCall->getCXXThisVal());
  }

  FuncCaseType ThisFunc = std::make_pair(FunctionName, std::make_pair(num,Args));

  if (!IsCompareFunction(FunctionName)){

    //相同函数返回相同 （非比较函数）
    bool HasSame = false;
    FuncSumType SameFunc;
    for (auto It:FuncSumList){
      if (IsSameRoad(It.second,nowroad))
        if (IsSameFunction(It.first.first,ThisFunc,State,SVB)){
          HasSame = true;
          SameFunc = It;
          break;
        }
    }

    if (HasSame){
      SVal SameRet = SameFunc.first.second;
    
      if (!(ThisRet.getAs<nonloc::ConcreteInt>() && SameRet.getAs<nonloc::ConcreteInt>())) {
        if (auto ThisLoc = ThisRet.getAs<Loc>()){    
          SameSValList.push_back(std::make_pair(std::make_pair(SameRet,ThisRet),nowroad));
          SameSValList.push_back(std::make_pair(std::make_pair(ThisRet,SameRet),nowroad));
          updateSValList(State,SVB);
        } else if (auto ThisLazy = ThisRet.getAs<clang::ento::nonloc::LazyCompoundVal>()){
          const MemRegion *ThisRegion = ThisLazy->getRegion();
          auto SameLazy = SameRet.getAs<clang::ento::nonloc::LazyCompoundVal>();
          const MemRegion *SameRegion = SameLazy->getRegion();
          SameLazyFuncList.push_back(std::make_pair(std::make_pair(SameRegion,ThisRegion),nowroad));
          SameLazyFuncList.push_back(std::make_pair(std::make_pair(ThisRegion,SameRegion),nowroad));
          updateLazyFuncList(State,SVB);
        } else { 
          QualType ThisType = ThisRet.getType(C.getASTContext());
          if (!ThisType.isNull() && ThisType->isIntegerType() && (isa<NonLoc>(ThisRet)) && (isa<NonLoc>(SameRet))){
            SVal EqualSVal = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), SameRet.castAs<NonLoc>(), SVB.getContext().IntTy);
            if (isa<NonLoc>(EqualSVal)) {
              ProgramStateRef EqualState = State->assume(EqualSVal.castAs<NonLoc>(), true); 

              if (EqualState) {
                State = EqualState;
              }
            }
          }
          SameSValList.push_back(std::make_pair(std::make_pair(SameRet,ThisRet),nowroad));
          SameSValList.push_back(std::make_pair(std::make_pair(ThisRet,SameRet),nowroad));
          updateSValList(State,SVB);
        }
        State = State->BindExpr(Call.getOriginExpr(),C.getLocationContext(),SameRet);
      }
    }

    if (!HasSame){

      llvm::errs()<<"insert:\n";
      llvm::errs()<<ThisFunc.first<<" : ";
      for (size_t i=0; i<ThisFunc.second.second.size();i++){
        ThisFunc.second.second[i].dump();
        llvm::errs()<<" ";
      }

      FuncSumList.push_back(std::make_pair(std::make_pair(ThisFunc,ThisRet),nowroad));     
      
    }
    C.addTransition(State);
    return;
  }

  //反自反性对参数影响
  if (ThisRet.getAs<NonLoc>()) {
    QualType RetType = ThisRet.getType(C.getASTContext());
    if (RetType == C.getASTContext().BoolTy){
      ProgramStateRef StateTrue = State->assume(ThisRet.castAs<NonLoc>(), true);
      if (StateTrue){
        if (Args[0].getAs<NonLoc>())
          if (Args[1].getAs<NonLoc>()) {
            SVal EqualSVal = SVB.evalBinOpNN(StateTrue, BO_NE, Args[0].castAs<NonLoc>(), Args[1].castAs<NonLoc>(), SVB.getContext().IntTy);//需要对nonloc进行保护,可能会漏约束
            ProgramStateRef StateNotEqual =  StateTrue->assume(EqualSVal.castAs<NonLoc>(), true);
            if (StateNotEqual)
              State = StateNotEqual;  
          }
      }
    }
    else if (RetType == C.getASTContext().IntTy){            
      SVal Zero = SVB.makeIntVal(0,SVB.getContext().IntTy);

      SVal ThisRetEqualZero = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      
      ProgramStateRef StateTrue = State->assume(ThisRetEqualZero.castAs<NonLoc>(), true); 
      if (StateTrue) {
        if (Args[0].getAs<NonLoc>())
          if (Args[1].getAs<NonLoc>()) {
            SVal EqualSVal = SVB.evalBinOpNN(StateTrue, BO_EQ, Args[0].castAs<NonLoc>(), Args[1].castAs<NonLoc>(), SVB.getContext().IntTy);
            ProgramStateRef StateEqual =  StateTrue->assume(EqualSVal.castAs<NonLoc>(), true);
            if (StateEqual){
              State = StateEqual;
            }              
          }
        SameSValList.push_back(std::make_pair(std::make_pair(Args[0],Args[1]),nowroad));
        SameSValList.push_back(std::make_pair(std::make_pair(Args[1],Args[0]),nowroad));
        updateSValList(State,SVB);
      }
    }
  }

  //反对称性对参数影响
  bool HasPartExchangeFunc = false;
  FuncSumType PartExchangeFunc;
  for (auto It : FuncSumList){    
    if (IsSameRoad(It.second,nowroad))
      if (IsPartExchangeFunction(It.first.first,ThisFunc,State,SVB)) {
        HasPartExchangeFunc = true;
        PartExchangeFunc = It;
        break;
      }
  }

  if (HasPartExchangeFunc && ThisRet.getAs<NonLoc>()){  
    SVal ExRet = PartExchangeFunc.first.second;

    QualType RetType = ThisRet.getType(C.getASTContext());
    if (RetType == C.getASTContext().BoolTy){
      //暂时不考虑参数不为2的比较函数的情况
      SVal First = PartExchangeFunc.first.first.second.second[0];
      SVal Second = Args[1];

      ProgramStateRef State1 = State->assume(ThisRet.castAs<NonLoc>(), true);
      if (State1) {
        ProgramStateRef State2 = State1->assume(ExRet.castAs<NonLoc>(), true);
        if (State2) {
          ProgramStateRef NotEqualState;
          if (First.getAs<NonLoc>())
            if (Second.getAs<NonLoc>()){
              SVal NotEqualSVal =  SVB.evalBinOpNN(State2, BO_NE, First.castAs<NonLoc>(), Second.castAs<NonLoc>(), SVB.getContext().IntTy);
              NotEqualState = State2->assume(NotEqualSVal.castAs<NonLoc>(), true);
              if (NotEqualState) {
                State = NotEqualState;
              }
            }
        }
      }
    }
    else if (RetType == C.getASTContext().IntTy){
      SVal Zero = SVB.makeIntVal(0, SVB.getContext().IntTy);

      SVal ThisRetLessThanZero = SVB.evalBinOpNN(State, BO_LT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetEqualZero = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ThisRetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      SVal ExRetLessThanZero = SVB.evalBinOpNN(State, BO_LT, ExRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ExRetEqualZero = SVB.evalBinOpNN(State, BO_EQ, ThisRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);
      SVal ExRetGreaterThanZero = SVB.evalBinOpNN(State, BO_GT, ExRet.castAs<NonLoc>(), Zero.castAs<NonLoc>(), SVB.getContext().IntTy);

      SVal First = PartExchangeFunc.first.first.second.second[0];
      SVal Second = Args[1];
      bool PossibleEqual = false;
      ProgramStateRef State1 = State->assume(ThisRetLessThanZero.castAs<NonLoc>(), true);
      if (State1){
        ProgramStateRef State1_ExGt = State1->assume(ExRetGreaterThanZero.castAs<NonLoc>(), true);
        if (State1_ExGt) {
          State = State1_ExGt;
          PossibleEqual = true;
        }
      }

      ProgramStateRef State2 = State->assume(ThisRetGreaterThanZero.castAs<NonLoc>(), true);
      if (State2){
        ProgramStateRef State2_ExLe = State2->assume(ExRetLessThanZero.castAs<NonLoc>(), true);
        if (State2_ExLe) {
          State = State2_ExLe;
          PossibleEqual = true;
        }
      }

      ProgramStateRef State3 = State->assume(ThisRetEqualZero.castAs<NonLoc>(), true);
      if (State3){
        ProgramStateRef State3_Eq = State3->assume(ExRetEqualZero.castAs<NonLoc>(), true);
        if (State3_Eq) {
          State = State3_Eq;
          PossibleEqual = true;
        }
      }

      if (!PossibleEqual) {
        ProgramStateRef NotEqualState;
        if (First.getAs<NonLoc>())
          if (Second.getAs<NonLoc>()){
            SVal EqualSVal =  SVB.evalBinOpNN(State, BO_EQ, First.castAs<NonLoc>(), Second.castAs<NonLoc>(), SVB.getContext().IntTy);
            NotEqualState = State->assume(EqualSVal.castAs<NonLoc>(), false);
            if (NotEqualState)
              State = NotEqualState;
          }
      }
    }
  }
  bool HasSame = false;
  llvm::errs()<<"-----------------\n";
  for (auto It:FuncSumList){
    if (IsSameRoad(It.second,nowroad)) {
      llvm::errs()<<"Now have "<<It.first.first.first;
      llvm::errs()<<"\n";
      if (IsSameFunction(It.first.first,ThisFunc,State,SVB))
        HasSame = true;
    }
  }

  if (!HasSame){
    llvm::errs()<<"insert:\n";
    llvm::errs()<<ThisFunc.first<<" : ";
    for (size_t i=0; i<ThisFunc.second.second.size();i++){
    ThisFunc.second.second[i].dump();
      llvm::errs()<<" ";
    }
    llvm::errs()<<"\n";

    FuncSumList.push_back(std::make_pair(std::make_pair(ThisFunc,ThisRet),nowroad));
    
  }
  C.addTransition(State);
  return;
}



void FunctionSummary::checkPreStmt(const BinaryOperator *BO, CheckerContext &C) const{
  ProgramStateRef State = C.getState();
  SValBuilder &SVB = C.getSValBuilder(); 
  std::vector<size_t> nowroad = GetNowRoad(State);
  llvm::ImmutableListFactory<std::pair<SVal, SVal>> SameSVallistFactory;
  
  if (BO->getOpcode() == BO_LT) {
    const Expr *LHS = BO->getLHS();
    const Expr *RHS = BO->getRHS();
    const Expr *Expr = BO->getExprStmt();

    SVal lhsVal = C.getSVal(LHS);
    SVal rhsVal = C.getSVal(RHS);

    if (IsSameVal(lhsVal,rhsVal, State, SVB)){
      SameSValList.push_back(std::make_pair(std::make_pair(lhsVal,rhsVal),nowroad));
      SameSValList.push_back(std::make_pair(std::make_pair(rhsVal,lhsVal),nowroad));
      updateSValList(State,SVB);

      SValBuilder &SVB = C.getSValBuilder();
      QualType lhsType = lhsVal.getType(C.getASTContext());
      QualType rhsType = rhsVal.getType(C.getASTContext());
      if ((!lhsType.isNull() && lhsType->isIntegerType()) && (!rhsType.isNull() && rhsType->isIntegerType())) {
        SVal Val = SVB.makeIntVal(0U, Expr->getType());
        ProgramStateRef NewState = State->BindExpr(Expr, C.getLocationContext(), Val);
        if (NewState)
          State = NewState;
      }
    }
    C.addTransition(State);
  }
  
  if (BO->getOpcode() == BO_GT) {
    const Expr *LHS = BO->getLHS();
    const Expr *RHS = BO->getRHS();
    const Expr *Expr = BO->getExprStmt();

    SVal lhsVal = C.getSVal(LHS);
    SVal rhsVal = C.getSVal(RHS);

    if (IsSameVal(lhsVal,rhsVal, State, SVB)){
      SameSValList.push_back(std::make_pair(std::make_pair(lhsVal,rhsVal),nowroad));
      SameSValList.push_back(std::make_pair(std::make_pair(rhsVal,lhsVal),nowroad));
      updateSValList(State,SVB);
      
      SValBuilder &SVB = C.getSValBuilder();
      QualType lhsType = lhsVal.getType(C.getASTContext());
      QualType rhsType = rhsVal.getType(C.getASTContext());
      if ((!lhsType.isNull() && lhsType->isIntegerType()) && (!rhsType.isNull() && rhsType->isIntegerType())) {
        SVal Val = SVB.makeIntVal(0U, Expr->getType());
        ProgramStateRef NewState = State->BindExpr(Expr, C.getLocationContext(), Val);
        if (NewState)
          State = NewState;
      }
    }
    C.addTransition(State);
  }

  if (BO->getOpcode() == BO_EQ) {
    const Expr *LHS = BO->getLHS();
    const Expr *RHS = BO->getRHS();
    const Expr *Expr = BO->getExprStmt();

    SVal lhsVal = C.getSVal(LHS);
    SVal rhsVal = C.getSVal(RHS);

    if (IsSameVal(lhsVal,rhsVal, State, SVB)){
      SameSValList.push_back(std::make_pair(std::make_pair(lhsVal,rhsVal),nowroad));
      SameSValList.push_back(std::make_pair(std::make_pair(rhsVal,lhsVal),nowroad));
      updateSValList(State,SVB);
      
      SValBuilder &SVB = C.getSValBuilder();
      QualType lhsType = lhsVal.getType(C.getASTContext());
      QualType rhsType = rhsVal.getType(C.getASTContext());
      if ((!lhsType.isNull() && lhsType->isIntegerType()) && (!rhsType.isNull() && rhsType->isIntegerType())) {
        SVal Val = SVB.makeIntVal(1U, Expr->getType());
        ProgramStateRef NewState = State->BindExpr(Expr, C.getLocationContext(), Val);
        if (NewState)
          State = NewState;
      }
    }
    C.addTransition(State);
  }
  
  if (BO->getOpcode() == BO_NE) {
    const Expr *LHS = BO->getLHS();
    const Expr *RHS = BO->getRHS();
    const Expr *Expr = BO->getExprStmt();

    SVal lhsVal = C.getSVal(LHS);
    SVal rhsVal = C.getSVal(RHS);

    if (IsSameVal(lhsVal,rhsVal, State, SVB)){
      SameSValList.push_back(std::make_pair(std::make_pair(lhsVal,rhsVal),nowroad));
      SameSValList.push_back(std::make_pair(std::make_pair(rhsVal,lhsVal),nowroad));
      updateSValList(State,SVB);
      
      SValBuilder &SVB = C.getSValBuilder();
      QualType lhsType = lhsVal.getType(C.getASTContext());
      QualType rhsType = rhsVal.getType(C.getASTContext());
      if ((!lhsType.isNull() && lhsType->isIntegerType()) && (!rhsType.isNull() && rhsType->isIntegerType())) {
        SVal Val = SVB.makeIntVal(0U, Expr->getType());
        ProgramStateRef NewState = State->BindExpr(Expr, C.getLocationContext(), Val);
        if (NewState)
          State = NewState;
      }
    }
    C.addTransition(State);
  }

  if (BO->getOpcode() == BO_Sub){
    ProgramStateRef State = C.getState();
    SValBuilder &SVB = C.getSValBuilder();

    SVal LHS = C.getSVal(BO->getLHS());
    SVal RHS = C.getSVal(BO->getRHS());

    if (LHS.getAs<NonLoc>()) {
      NonLoc Ten = SVB.makeIntVal(10, BO->getType()).castAs<NonLoc>();
      NonLoc MinusTen = SVB.makeIntVal(-10, BO->getType()).castAs<NonLoc>();
      SVal LessTen = SVB.evalBinOpNN(State, BO_LT, LHS.castAs<NonLoc>(), Ten, BO->getType());
      ProgramStateRef NewState = State->assume(LessTen.castAs<NonLoc>(), true);
      if (NewState)
        State = NewState;
      SVal GreterMinusTen = SVB.evalBinOpNN(State, BO_GT, LHS.castAs<NonLoc>(), MinusTen, BO->getType());
      NewState = State->assume(GreterMinusTen.castAs<NonLoc>(), true);
      if (NewState)
        State = NewState;
    }

    if (RHS.getAs<NonLoc>()) {
      NonLoc Ten = SVB.makeIntVal(10, BO->getType()).castAs<NonLoc>();
      NonLoc MinusTen = SVB.makeIntVal(-10, BO->getType()).castAs<NonLoc>();
      SVal LessTen = SVB.evalBinOpNN(State, BO_LT, RHS.castAs<NonLoc>(), Ten, BO->getType());
      ProgramStateRef NewState = State->assume(LessTen.castAs<NonLoc>(), true);
      if (NewState)
        State = NewState;
      SVal GreaterMinusTen = SVB.evalBinOpNN(State, BO_GT, RHS.castAs<NonLoc>(), MinusTen, BO->getType());
      NewState = State->assume(GreaterMinusTen.castAs<NonLoc>(), true);
      if (NewState)
        State = NewState;
    }


    C.addTransition(State);
  }
}

void FunctionSummary::checkEndAnalysis(ExplodedGraph &G, BugReporter &BR, ExprEngine &Eng) const {
    unsigned PathCount = 0;

    // 遍历 ExplodedGraph 中的叶子节点
    for (auto Node : G.nodes()) {
        if (Node.isSink()) {
            // 叶子节点表示路径终点
            ++PathCount;
        }
    }

    llvm::outs() << "Total paths analyzed: " << PathCount << "\n";
}


void ento::registerFunctionSummary(CheckerManager &Mgr) {
  Mgr.registerChecker<FunctionSummary>();
}

bool ento::shouldRegisterFunctionSummary(const CheckerManager &Mgr) {
  return true;
}
