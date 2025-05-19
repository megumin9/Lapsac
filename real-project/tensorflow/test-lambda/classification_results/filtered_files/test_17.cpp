#include <bits/stdc++.h>
using namespace std;

struct NodeDef {
    const string& name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const NodeDef* n1, const NodeDef* n2) {
  return n1->name() < n2->name();
}

void test1(const NodeDef* a, const NodeDef* b, const NodeDef* c){
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const NodeDef* a, const NodeDef* b, const NodeDef* c){
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const NodeDef* a, const NodeDef* b){
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const NodeDef* a){
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}