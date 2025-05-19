#include <bits/stdc++.h>
using namespace std;

struct bNode {
    int location[2];
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const bNode *a, const bNode *b) {
  return a->location[0] < b->location[0];
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
  if (lambda2(a,a))
    ReflexivityChecker();
}