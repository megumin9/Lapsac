
#include <bits/stdc++.h>
using namespace std;

struct bNode {
    unsigned int ui_order;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(bNode *a, bNode *b) {
  return a->ui_order < b->ui_order;
}

void test1(bNode *a, bNode *b, bNode *c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
    ConsistencyChecker();
}

void test2(bNode *a, bNode *b, bNode *c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
    TransiveChecker();
}

void test3_1(bNode *a, bNode *b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test3_2(bNode *a, bNode *b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test4(bNode *a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}
