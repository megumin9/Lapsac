#include <bits/stdc++.h>
struct MemPrintBlock {
    int len;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_len(const void *p1, const void *p2) {
  const MemPrintBlock *pb1 = (const MemPrintBlock *)p1;
  const MemPrintBlock *pb2 = (const MemPrintBlock *)p2;

  if (pb1->len < pb2->len) {
    return 1;
  }
  if (pb1->len == pb2->len) {
    return 0;
  }
  return -1;
}

void test1(void *a, void *b, void *c) {
  NewTest();
  if (!(compare_len(a,b)<0) && !(compare_len(b,c)<0) && (compare_len(a,c)<0))
    ConsistencyChecker();
}

void test2(void *a, void *b, void *c) {
  NewTest();
  if ((compare_len(a,b)<0) && (compare_len(b,c)<0) && (compare_len(c,a)<0))
    TransiveChecker();
}

void test3_1(void *a, void *b) {
  NewTest();
  if ((compare_len(a,b)>0)&&(compare_len(b,a)>0))
    SymmetryChecker();
}

void test3_2(void *a, void *b) {
  NewTest();
  if ((compare_len(a,b)<0)&&(compare_len(b,a)<0))
    SymmetryChecker();
}

void test4(void *a) {
  NewTest();
  if (compare_len(a, a)<0||compare_len(a, a)>0)
    ReflexivityChecker();
}