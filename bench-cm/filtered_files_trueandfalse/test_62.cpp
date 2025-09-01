#include <bits/stdc++.h>
struct ComputeProgramKey {
  int shader;
  int layout;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_26(const ComputeProgramKey &a, const ComputeProgramKey &b) {
  if (a.shader < b.shader) return true;
  if (a.shader > b.shader) return false;
  if (a.layout < b.layout) return true;
  return false;
}

void test1(const ComputeProgramKey &a, const ComputeProgramKey &b, const ComputeProgramKey &c) {
  NewTest();
  if (!compare_26(a,b) && !compare_26(b,c) && compare_26(a,c))
    ConsistencyChecker();
}

void test2(const ComputeProgramKey &a, const ComputeProgramKey &b, const ComputeProgramKey &c) {
  NewTest();
  if (compare_26(a,b) && compare_26(b,c) && compare_26(c,a))
    TransiveChecker();
}

void test3_1(const ComputeProgramKey &a, const ComputeProgramKey &b) {
  NewTest();
  if (compare_26(a,b) && compare_26(b,a))
    SymmetryChecker();
}

void test3_2(const ComputeProgramKey &a, const ComputeProgramKey &b) {
  NewTest();
  if (compare_26(a,b) && compare_26(b,a))
    SymmetryChecker();
}

void test4(const ComputeProgramKey &a) {
  NewTest();
  if (compare_26(a, a))
    ReflexivityChecker();
}