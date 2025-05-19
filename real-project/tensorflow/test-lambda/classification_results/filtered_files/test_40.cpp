#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const int64_t lhs, const int64_t rhs) {
  return lhs < rhs;
}

void test1(int64_t a, int64_t b, int64_t c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(int64_t a, int64_t b, int64_t c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(int64_t a, int64_t b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(int64_t a, int64_t b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(int64_t a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}