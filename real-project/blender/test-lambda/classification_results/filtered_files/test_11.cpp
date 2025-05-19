#include <bits/stdc++.h>
using namespace std;

struct EdgeUUID {
    int edval;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const EdgeUUID &a, const EdgeUUID &b) {
  return a.edval < b.edval;
}

void test1(EdgeUUID a, EdgeUUID b, EdgeUUID c) {
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(EdgeUUID a, EdgeUUID b, EdgeUUID c) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(EdgeUUID a, EdgeUUID b) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(EdgeUUID a) {
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}