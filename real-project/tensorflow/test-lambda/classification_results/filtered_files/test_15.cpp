#include <bits/stdc++.h>

struct InputOffsetWithCycleIdx {
    int input_element_index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const InputOffsetWithCycleIdx& lhs,
             const InputOffsetWithCycleIdx& rhs) {
  return lhs.input_element_index < rhs.input_element_index;
}

void test1(InputOffsetWithCycleIdx a, InputOffsetWithCycleIdx b, InputOffsetWithCycleIdx c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(InputOffsetWithCycleIdx a, InputOffsetWithCycleIdx b, InputOffsetWithCycleIdx c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(InputOffsetWithCycleIdx a, InputOffsetWithCycleIdx b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(InputOffsetWithCycleIdx a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}