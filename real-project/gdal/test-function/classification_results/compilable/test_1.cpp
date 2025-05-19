#include <bits/stdc++.h>

struct facetT {
    bool isarea;
    struct { int area; } f;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int qh_compare_facetarea(const void *p1, const void *p2) {
  const facetT *a= *((facetT *const*)p1), *b= *((facetT *const*)p2);

  if (!a->isarea)
    return -1;
  if (!b->isarea)
    return 1;
  if (a->f.area > b->f.area)
    return 1;
  else if (a->f.area == b->f.area)
    return 0;
  return -1;
}

void test1(void *a, void *b, void *c) {
  NewTest();
  if (!(qh_compare_facetarea(a,b)<0) && !(qh_compare_facetarea(b,c)<0) && (qh_compare_facetarea(a,c)<0))
    ConsistencyChecker();
}

void test2(void *a, void *b, void *c) {
  NewTest();
  if ((qh_compare_facetarea(a,b)<0) && (qh_compare_facetarea(b,c)<0) && (qh_compare_facetarea(c,a)<0))
    TransiveChecker();
}

void test3_1(void *a, void *b) {
  NewTest();
  if ((qh_compare_facetarea(a,b)>0)&&(qh_compare_facetarea(b,a)>0))
    SymmetryChecker();
}

void test3_2(void *a, void *b) {
  NewTest();
  if ((qh_compare_facetarea(a,b)<0)&&(qh_compare_facetarea(b,a)<0))
    SymmetryChecker();
}

void test4(void *a) {
  NewTest();
  if (qh_compare_facetarea(a, a)!=0)
    ReflexivityChecker();
}