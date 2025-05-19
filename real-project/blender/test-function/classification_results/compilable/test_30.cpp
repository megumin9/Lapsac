#include <bits/stdc++.h>
using namespace std;

struct TransData {
    int rdist;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int trans_data_compare_rdist(const void *a, const void *b) {
  const TransData *td_a = (const TransData *)a;
  const TransData *td_b = (const TransData *)b;

  if (td_a->rdist < td_b->rdist) return -1;
  if (td_a->rdist > td_b->rdist) return 1;
  return 0;
}

void test1(const void *a, const void *b, const void *c) {
  NewTest();
  if (!(trans_data_compare_rdist(a,b) < 0) && 
      !(trans_data_compare_rdist(b,c) < 0) && 
      (trans_data_compare_rdist(a,c) < 0)) {
    ConsistencyChecker();
  }
}

void test2(const void *a, const void *b, const void *c) {
  NewTest();
  if ((trans_data_compare_rdist(a,b) < 0) && 
      (trans_data_compare_rdist(b,c) < 0) && 
      (trans_data_compare_rdist(c,a) < 0)) {
    TransiveChecker();
  }
}

void test3_1(const void *a, const void *b) {
  NewTest();
  if ((trans_data_compare_rdist(a,b) > 0) && 
      (trans_data_compare_rdist(b,a) > 0)) {
    SymmetryChecker();
  }
}

void test3_2(const void *a, const void *b) {
  NewTest();
  if ((trans_data_compare_rdist(a,b) < 0) && 
      (trans_data_compare_rdist(b,a) < 0)) {
    SymmetryChecker();
  }
}

void test4(const void *a) {
  NewTest();
  if (trans_data_compare_rdist(a,a) < 0 || 
      trans_data_compare_rdist(a,a) > 0) {
    ReflexivityChecker();
  }
}