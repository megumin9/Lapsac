#include <bits/stdc++.h>

struct NodeDef;

extern std::map<const NodeDef*, int> components;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const NodeDef* first, const NodeDef* second) {
  return components.find(first)->second < components.find(second)->second;
}

void test1(const NodeDef* a, const NodeDef* b, const NodeDef* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const NodeDef* a, const NodeDef* b, const NodeDef* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const NodeDef* a, const NodeDef* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const NodeDef* a, const NodeDef* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const NodeDef* a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}