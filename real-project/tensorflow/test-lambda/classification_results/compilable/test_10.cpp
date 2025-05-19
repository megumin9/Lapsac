#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();
int tensor_names_flat(size_t a);

bool lambda0(size_t a, size_t b) {
  return tensor_names_flat(a) < tensor_names_flat(b);
}

void test1(size_t a, size_t b, size_t c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(size_t a, size_t b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(size_t a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}