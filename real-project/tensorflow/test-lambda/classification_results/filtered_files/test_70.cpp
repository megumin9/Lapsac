#include <bits/stdc++.h>
using namespace std;

struct PerLayerInfo {
    int total_bytes;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const PerLayerInfo* l, const PerLayerInfo* r) {
  return l->total_bytes > r->total_bytes;
}

void test1(const PerLayerInfo* a, const PerLayerInfo* b, const PerLayerInfo* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const PerLayerInfo* a, const PerLayerInfo* b, const PerLayerInfo* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const PerLayerInfo* a, const PerLayerInfo* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const PerLayerInfo* a, const PerLayerInfo* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const PerLayerInfo* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}