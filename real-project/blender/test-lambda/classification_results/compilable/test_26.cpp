
#include <bits/stdc++.h>
struct bNode {
    unsigned int ui_order;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const bNode *a, const bNode *b) {
  return a->ui_order > b->ui_order;
}

void test1(const bNode *a, const bNode *b, const bNode *c) {
  NewTest();
  if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(const bNode *a, const bNode *b, const bNode *c) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(const bNode *a, const bNode *b) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(const bNode *a) {
  NewTest();
  if (lambda2(a, a))
    ReflexivityChecker();
}
