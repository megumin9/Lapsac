#include "clang/StaticAnalyzer/Checkers/BuiltinCheckerRegistration.h"
#include "clang/StaticAnalyzer/Core/BugReporter/BugType.h"
#include "clang/StaticAnalyzer/Core/Checker.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CallEvent.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CheckerContext.h"
#include "clang/AST/DeclTemplate.h"
#include "clang/Driver/DriverDiagnostic.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/CallDescription.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/DynamicType.h"
#include "clang/StaticAnalyzer/Core/PathSensitive/ProgramStateTrait.h"
#include "llvm/ADT/ImmutableList.h"
#include <optional>
#include <regex>

using std::optional;
using namespace clang;
using namespace ento;
using namespace std;

int ReflexivityWrongPath = 0;
int SymmetryWrongPath = 0;
int TransitivityWrongPath = 0;
int ConsistencyWrongPath = 0;

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
namespace {

class FunctionChecker
  : public Checker<check::PreStmt<CallExpr>> {  
  std::unique_ptr<BugType> ReflexivityBugType;
  std::unique_ptr<BugType> SymmetryBugType;
  std::unique_ptr<BugType> TransiveBugType;
  std::unique_ptr<BugType> ConsistencyBugType;
  void reportBug(const StringRef &Message, CheckerContext &C,
                                ExplodedNode *ErrNode, BugType *BT) const; 
  
public:
  FunctionChecker();

  void checkPreStmt(const CallExpr *CE, CheckerContext &C) const; 
};

} //namespace

FunctionChecker::FunctionChecker(){
  ReflexivityBugType.reset(
      new BugType(this, "Violation of Anti-Reflexivity", "Compare Operator Bug"));
  SymmetryBugType.reset(
      new BugType(this, "Violation of Anti-Symmetry", "Compare Operator Bug"));
  TransiveBugType.reset(
      new BugType(this, "Violation of Transitivity", "Compare Operator Bug"));
  ConsistencyBugType.reset(
      new BugType(this, "Violation of Consistency", "Compare Operator Bug"));
}

bool IfTrueReportttt(ExplodedNode *N, CheckerContext &C) {
  if (!N) return false;

  const SourceManager &SM = C.getSourceManager();

  unsigned int lastLine = 0;
  unsigned int line = 0;
  ProgramPoint P = N->getLocation();
  if (auto SP = P.getAs<StmtPoint>()) {
    if (const Stmt *S = SP->getStmt()) {
      line = SM.getSpellingLineNumber(S->getBeginLoc());
      lastLine = line;
    }
  }

  while (N) {
    P = N->getLocation();
    if (auto SP = P.getAs<StmtPoint>()) {
      if (const Stmt *S = SP->getStmt()) {
        line = SM.getSpellingLineNumber(S->getBeginLoc());
        if (abs(int(line-lastLine))>=5) { 
          break;
        }
      }
    }
    N = N->getFirstPred();
  }
  
  SourceLocation loc = SM.translateLineCol(SM.getMainFileID(), line, 1);
  const LangOptions &LangOpts = C.getASTContext().getLangOpts();
  string statement = "";
    
  while (loc.isValid()) {
    unsigned line = SM.getExpansionLineNumber(loc);
    SourceLocation lineStart = SM.translateLineCol(SM.getMainFileID(), line, 1);
    SourceLocation lineEnd = Lexer::findLocationAfterToken(lineStart, tok::semi, SM, LangOpts, true);

    if (!lineEnd.isValid()) {
      lineEnd = SM.translateLineCol(SM.getMainFileID(), line + 1, 1);
    }

    CharSourceRange range = CharSourceRange::getCharRange(lineStart, lineEnd);
    StringRef lineText = Lexer::getSourceText(range, SM, LangOpts);
    
    size_t newlinePos = lineText.find('\n');
    if (newlinePos != StringRef::npos) {
        lineText = lineText.substr(0, newlinePos);
    }

    statement += lineText.str();
    if (lineText.find(';') != StringRef::npos) {
      break;
    }
    line++;
    loc = SM.translateLineCol(SM.getMainFileID(), line, 1);
  }

  statement = std::regex_replace(statement, std::regex("\\s+"), " ");
  statement.erase(std::remove(statement.begin(), statement.end(), '\n'), statement.end());
  StringRef Trimmed = StringRef(statement).trim();

  if (Trimmed.starts_with("return ")) {
    Trimmed = Trimmed.drop_front(7).trim();
  }

  if (Trimmed == "true" || Trimmed.front() == '-' || isDigit(Trimmed.front())) {
    return true;
  }

  if (Trimmed.contains('=')){
    return true;
  }
        
  std::regex pattern(R"(\s[<>-]\s)");
  std::regex andpattern(R"(\s&&\s)");
  std::regex orpattern(R"(\s\|\|\s)");
  std::string x = Trimmed.str();
  if (std::regex_search(x, pattern)){
    if (std::regex_search(x, andpattern))
      return true; 
    if (std::regex_search(x, orpattern))
      return true; 
    if (Trimmed.contains('?'))
      return true;
    return false;
  }


  size_t parenPos = Trimmed.find('(');
  if (parenPos != StringRef::npos) {
    StringRef BeforeParen = Trimmed.slice(0, parenPos).trim();
    if (!BeforeParen.empty() && BeforeParen.find(' ') == StringRef::npos && BeforeParen.find('!') == StringRef::npos) {
      return false; 
    }
  }      
  return true;
}

bool IfTrueReportmegumin(ExplodedNode *N, CheckerContext &C) {
  if (!N) return false;

  std::vector<int> roadline;
  const SourceManager &SM = C.getSourceManager();
  ExplodedNode * OriginN = N;
  unsigned int lastLine = 0; 
  ProgramPoint P = N->getLocation();
  StringRef NowFile;
  if (auto SP = P.getAs<StmtPoint>()) {
    if (SP->getStmt()) {
      SourceLocation Loc;
      Loc = SP->getStmt()->getBeginLoc();
      PresumedLoc PLoc = SM.getPresumedLoc(Loc);
      if (!PLoc.isValid()) {
        return false;
      }
      NowFile = PLoc.getFilename();
    }
  }

  while (N) {
    ProgramPoint P = N->getLocation();
    if (auto SP = P.getAs<StmtPoint>()) {
      if (const Stmt *S = SP->getStmt()) {
        SourceLocation Loc;
        Loc = SP->getStmt()->getBeginLoc();
        PresumedLoc PLoc = SM.getPresumedLoc(Loc);
        if (!PLoc.isValid()) {
          N = N->getFirstPred();
          continue;
        }
        StringRef Filename = PLoc.getFilename();
        if (Filename != NowFile){
          N = N->getFirstPred();
          continue;
        }
        unsigned line = SM.getSpellingLineNumber(S->getBeginLoc());
        roadline.push_back(line);
        if (line != lastLine) { 
          lastLine = line; 
        }
      }
    }
    N = N->getFirstPred();
  }

  int finalret = roadline[0];
  std::vector<int> retline;
  bool ifintest = true;
  for (unsigned int i = 1; i<roadline.size();i++) {
    if (roadline[i] > finalret)
      continue;
    if (ifintest && finalret - roadline[i] >= 5){
      ifintest = false;
      retline.push_back(roadline[i]);
    }
    if (!ifintest && finalret - roadline[i] < 5){
      ifintest = true;
    }
  }

  if (retline.size() == 2 && retline[0] == retline[1])
    return IfTrueReportttt(OriginN, C);
  return true;
}

bool IfTrueReportseki(ExplodedNode *N, CheckerContext &C) {
  if (!N) return false;

  std::vector<int> roadline;
  const SourceManager &SM = C.getSourceManager();

  unsigned int lastLine = 0; 
  ProgramPoint P = N->getLocation();
  StringRef NowFile;
  if (auto SP = P.getAs<StmtPoint>()) {
    if (SP->getStmt()) {
      SourceLocation Loc;
      Loc = SP->getStmt()->getBeginLoc();
      PresumedLoc PLoc = SM.getPresumedLoc(Loc);
      if (!PLoc.isValid()) {
        return false;
      }
      NowFile = PLoc.getFilename();
    }
  }

  while (N) {
    ProgramPoint P = N->getLocation();
    if (auto SP = P.getAs<StmtPoint>()) {
      if (const Stmt *S = SP->getStmt()) {
        SourceLocation Loc;
        Loc = SP->getStmt()->getBeginLoc();
        PresumedLoc PLoc = SM.getPresumedLoc(Loc);
        if (!PLoc.isValid()) {
          N = N->getFirstPred();
          continue;
        }
        StringRef Filename = PLoc.getFilename();
        if (Filename != NowFile){
          N = N->getFirstPred();
          continue;
        }
        unsigned line = SM.getSpellingLineNumber(S->getBeginLoc());
        roadline.push_back(line);
        if (line != lastLine) { 
          lastLine = line; 
        }
      }
    }
    N = N->getFirstPred();
  }

  int finalret = roadline[0];
  std::vector<int> retline;
  bool ifintest = true;
  for (unsigned int i = 1; i<roadline.size();i++) {
    if (roadline[i] > finalret)
      continue;
    if (ifintest && finalret - roadline[i] >= 5){
      ifintest = false;
      retline.push_back(roadline[i]);
    }
    if (!ifintest && finalret - roadline[i] < 5){
      ifintest = true;
    }
  }

  if (retline.size() == 3 && retline[0] == retline[1] && retline[1] == retline[2])
    return false;
  
  return true;
}

void FunctionChecker::checkPreStmt(const CallExpr *CE, CheckerContext &C) const{
    if (const FunctionDecl *FD = CE->getDirectCallee()) {
      if (FD->getNameAsString() == "ReflexivityChecker") {
        if (ReflexivityWrongPath<10) {
          ReflexivityWrongPath ++;
          auto *N = C.generateErrorNode(C.getState());
          if (IfTrueReportttt(N,C))
            reportBug("Violation of Anti-Reflexivity", C , N, ReflexivityBugType.get());
        } else{
          llvm::errs() <<"ReflexivityWrongPath more than 10";
        }
      }
      if (FD->getNameAsString() == "SymmetryChecker") {
        if (SymmetryWrongPath<30) {
          SymmetryWrongPath ++;
          auto *N = C.generateErrorNode(C.getState());
          if (IfTrueReportmegumin(N,C))
            reportBug("Violation of Anti-Symetry", C , N, SymmetryBugType.get());
        } else {
          llvm::errs() <<"SymmetryWrongPath more than 30";
        }
      }
      if (FD->getNameAsString() == "TransiveChecker") {
        if (TransitivityWrongPath<50) {
          TransitivityWrongPath ++;
          auto *N = C.generateErrorNode(C.getState());
          if (IfTrueReportseki(N,C)) {
            std::vector<size_t> nowroad;
            size_t i = 0;
            llvm::errs() << "The Error Road is: x";
            while (auto It=C.getState()->get<TestMap>(i)){
              llvm::errs() << It->getNumber();
              nowroad.push_back(It->getNumber());
              i = i + 1;
            }
            llvm::errs() << "\n";
            reportBug("Violation of Transitivity", C , N, TransiveBugType.get());
          }
        } else {
          llvm::errs() <<"TransitivityWrongPath more than 50";
        }
      } 
      if (FD->getNameAsString() == "ConsistencyChecker") {
        if (ConsistencyWrongPath<50) {
          ConsistencyWrongPath ++;
          auto *N = C.generateErrorNode(C.getState());
          if (IfTrueReportseki(N,C))
            reportBug("Violation of Consistency", C , N, ConsistencyBugType.get());
        } else {
          llvm::errs() <<"ConsistencyWrongPath more than 50";
        }
      }
    }
}

void FunctionChecker::reportBug(const StringRef &Message, CheckerContext &C,
                                ExplodedNode *ErrNode,BugType *BT) const {
  auto R = std::make_unique<PathSensitiveBugReport>(*BT, Message, ErrNode);
  C.emitReport(std::move(R));
}

void ento::registerFunctionChecker(CheckerManager &mgr) {
  mgr.registerChecker<FunctionChecker>();
}

bool ento::shouldRegisterFunctionChecker(const CheckerManager &mgr) {
  return true;
}
