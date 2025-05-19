#include <bits/stdc++.h>
using namespace std;

struct NodeSet {
    int size;
};

struct TfLiteDelegateParams {
    NodeSet* nodes_to_replace;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(TfLiteDelegateParams* left, TfLiteDelegateParams* right) {
  return left->nodes_to_replace->size > right->nodes_to_replace->size;
}

void test1(TfLiteDelegateParams* a, TfLiteDelegateParams* b, TfLiteDelegateParams* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(TfLiteDelegateParams* a, TfLiteDelegateParams* b, TfLiteDelegateParams* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(TfLiteDelegateParams* a, TfLiteDelegateParams* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(TfLiteDelegateParams* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}