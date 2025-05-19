#include <bits/stdc++.h>

struct HloInstruction {
    int parameter_number() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(HloInstruction* a, HloInstruction* b) {
  return a->parameter_number() > b->parameter_number();
}

void test1(HloInstruction* a, HloInstruction* b, HloInstruction* c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
    ConsistencyChecker();
}

void test2(HloInstruction* a, HloInstruction* b, HloInstruction* c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
    TransiveChecker();
}

void test3_1(HloInstruction* a, HloInstruction* b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test3_2(HloInstruction* a, HloInstruction* b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test4(HloInstruction* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}