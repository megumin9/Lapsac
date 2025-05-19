
#include <bits/stdc++.h>
struct SortVertsElem {
    int sum_co;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int svert_sum_cmp(const void *e1, const void *e2) {
  const SortVertsElem *sv1 = static_cast<const SortVertsElem *>(e1);
  const SortVertsElem *sv2 = static_cast<const SortVertsElem *>(e2);

  if (sv1->sum_co > sv2->sum_co) {
    return 1;
  }
  if (sv1->sum_co < sv2->sum_co) {
    return -1;
  }

  return 0;
}

void test1(void *a, void *b, void *c) {
  NewTest();
  if (!(svert_sum_cmp(a, b) < 0) && !(svert_sum_cmp(b, c) < 0) && (svert_sum_cmp(a, c) < 0)) 
    ConsistencyChecker();
}

void test2(void *a, void *b, void *c) {
  NewTest();
  if ((svert_sum_cmp(a, b) < 0) && (svert_sum_cmp(b, c) < 0) && (svert_sum_cmp(c, a) < 0)) 
    TransiveChecker();
}

void test3_1(void *a, void *b) {
  NewTest();
  if ((svert_sum_cmp(a, b) > 0) && (svert_sum_cmp(b, a) > 0))
    SymmetryChecker();
}

void test3_2(void *a, void *b) {
  NewTest();
  if ((svert_sum_cmp(a, b) < 0) && (svert_sum_cmp(b, a) < 0))
    SymmetryChecker();
}

void test4(void *a) {
  NewTest();
  if (svert_sum_cmp(a, a) < 0 || svert_sum_cmp(a, a) > 0) 
    ReflexivityChecker();
}
