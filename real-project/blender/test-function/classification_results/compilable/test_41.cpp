#include <bits/stdc++.h>

struct SortAnyByFloat {
    int sort_value;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int BLI_sortutil_cmp_float(const void *a_, const void *b_) {
  const SortAnyByFloat *a = static_cast<const SortAnyByFloat *>(a_);
  const SortAnyByFloat *b = static_cast<const SortAnyByFloat *>(b_);
  if (a->sort_value > b->sort_value) {
    return 1;
  }
  if (a->sort_value < b->sort_value) {
    return -1;
  }
  return 0;
}

void test1(const void* a, const void* b, const void* c) {
  NewTest();
  if (!(BLI_sortutil_cmp_float(a,b)<0) && !(BLI_sortutil_cmp_float(b,c)<0) && (BLI_sortutil_cmp_float(a,c)<0)) 
    ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c) {
  NewTest();
  if ((BLI_sortutil_cmp_float(a,b)<0) && (BLI_sortutil_cmp_float(b,c)<0) && (BLI_sortutil_cmp_float(c,a)<0)) 
    TransiveChecker();
}

void test3_1(const void* a, const void* b) {
  NewTest();
  if ((BLI_sortutil_cmp_float(a,b)>0)&&(BLI_sortutil_cmp_float(b,a)>0))
    SymmetryChecker();
}

void test3_2(const void* a, const void* b) {
  NewTest();
  if ((BLI_sortutil_cmp_float(a,b)<0)&&(BLI_sortutil_cmp_float(b,a)<0))
    SymmetryChecker();
}

void test4(const void* a) {
  NewTest();
  if (BLI_sortutil_cmp_float(a, a)<0||BLI_sortutil_cmp_float(a, a)>0) 
    ReflexivityChecker();
}