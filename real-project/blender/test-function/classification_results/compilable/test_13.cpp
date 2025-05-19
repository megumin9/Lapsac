#include <bits/stdc++.h>
struct ModePair {
    int val;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int modepair_cmp_by_val_inverse(const void *p1, const void *p2) {
  ModePair *r1 = (ModePair *)p1;
  ModePair *r2 = (ModePair *)p2;

  return (r1->val < r2->val) ? 1 : ((r1->val > r2->val) ? -1 : 0);
}

void test1(ModePair *a, ModePair *b, ModePair *c) {
  NewTest();
  if (!(modepair_cmp_by_val_inverse(a, b) < 0) && 
      !(modepair_cmp_by_val_inverse(b, c) < 0) && 
      (modepair_cmp_by_val_inverse(a, c) < 0)) {
    ConsistencyChecker();
  }
}

void test2(ModePair *a, ModePair *b, ModePair *c) {
  NewTest();
  if ((modepair_cmp_by_val_inverse(a, b) < 0) && 
      (modepair_cmp_by_val_inverse(b, c) < 0) && 
      (modepair_cmp_by_val_inverse(c, a) < 0)) {
    TransiveChecker();
  }
}

void test3_1(ModePair *a, ModePair *b) {
  NewTest();
  if ((modepair_cmp_by_val_inverse(a, b) > 0) && 
      (modepair_cmp_by_val_inverse(b, a) > 0)) {
    SymmetryChecker();
  }
}

void test3_2(ModePair *a, ModePair *b) {
  NewTest();
  if ((modepair_cmp_by_val_inverse(a, b) < 0) && 
      (modepair_cmp_by_val_inverse(b, a) < 0)) {
    SymmetryChecker();
  }
}

void test4(ModePair *a) {
  NewTest();
  if (modepair_cmp_by_val_inverse(a, a) < 0 || modepair_cmp_by_val_inverse(a, a) > 0) {
    ReflexivityChecker();
  }
}