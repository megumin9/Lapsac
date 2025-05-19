#include <bits/stdc++.h>
using namespace std;

struct StructuredValueDictEntry {
    int first;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const StructuredValueDictEntry* x, const StructuredValueDictEntry* y) {
  return x->first < y->first;
}

void test1(const StructuredValueDictEntry* a, const StructuredValueDictEntry* b, const StructuredValueDictEntry* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(const StructuredValueDictEntry* a, const StructuredValueDictEntry* b, const StructuredValueDictEntry* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(const StructuredValueDictEntry* a, const StructuredValueDictEntry* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const StructuredValueDictEntry* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}