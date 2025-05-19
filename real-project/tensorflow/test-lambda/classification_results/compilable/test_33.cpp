#include <bits/stdc++.h>

struct Node;
struct Edge {
    const Node* src() const;
};

struct Node {
    std::string name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Edge* a, const Edge* b) {
  return a->src()->name() < b->src()->name();
}

void test1(const Edge* a, const Edge* b, const Edge* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const Edge* a, const Edge* b, const Edge* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const Edge* a, const Edge* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const Edge* a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}