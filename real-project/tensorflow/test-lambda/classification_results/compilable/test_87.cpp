#include <bits/stdc++.h>
class HloInstruction;
class Shape;
const Shape& GetShape(const HloInstruction&);
int GetUniqueId(const HloInstruction&);
namespace ShapeUtil { int64_t ElementsIn(const Shape&); }
std::vector<HloInstruction*> GetOutputsOfFusible(const HloInstruction&);
int GetUniqueOutputTypeOfFusible(const HloInstruction&);
size_t GetOutputSizeOfFusible(const HloInstruction&);
int GetInstrCountOfFusible(const HloInstruction&);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const HloInstruction* a, const HloInstruction* b) {
  auto make_tuple_for_op = [](const HloInstruction* op) {
    return std::tuple{
        GetUniqueOutputTypeOfFusible(*op),
        GetOutputSizeOfFusible(*op), GetInstrCountOfFusible(*op),
        ShapeUtil::ElementsIn(GetShape(*GetOutputsOfFusible(*op)[0])),
        GetUniqueId(*op)};
  };
  return make_tuple_for_op(a) < make_tuple_for_op(b);
}

void test1(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(const HloInstruction* a, const HloInstruction* b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(const HloInstruction* a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}