
#include <bits/stdc++.h>
using namespace std;

struct HloInstruction {
    int unique_id() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const HloInstruction* a, const HloInstruction* b) {
  return a->unique_id() < b->unique_id();
}

void test1(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(const HloInstruction* a, const HloInstruction* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const HloInstruction* a, const HloInstruction* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const HloInstruction* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}
