#include <bits/stdc++.h>
using namespace std;

struct MemPrintBlock {
  const char* name;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_name(const void *p1, const void *p2) {
  const MemPrintBlock *pb1 = (const MemPrintBlock *)p1;
  const MemPrintBlock *pb2 = (const MemPrintBlock *)p2;
  return strcmp(pb1->name, pb2->name);
}

void test1(void *a, void *b, void *c) {
  NewTest();
  if (!(compare_name(a,b)<0) && !(compare_name(b,c)<0) && (compare_name(a,c)<0))
    ConsistencyChecker();
}

void test2(void *a, void *b, void *c) {
  NewTest();
  if ((compare_name(a,b)<0) && (compare_name(b,c)<0) && (compare_name(c,a)<0))
    TransiveChecker();
}

void test3_1(void *a, void *b) {
  NewTest();
  if ((compare_name(a,b)>0)&&(compare_name(b,a)>0))
    SymmetryChecker();
}

void test3_2(void *a, void *b) {
  NewTest();
  if ((compare_name(a,b)<0)&&(compare_name(b,a)<0))
    SymmetryChecker();
}

void test4(void *a) {
  NewTest();
  if (compare_name(a,a)<0||compare_name(a,a)>0)
    ReflexivityChecker();
}