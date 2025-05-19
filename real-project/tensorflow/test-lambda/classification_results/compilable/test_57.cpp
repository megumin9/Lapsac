
#include <bits/stdc++.h>

struct SimpleNode {
    const std::string& name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const SimpleNode* lhs, const SimpleNode* rhs) {
  return lhs->name() < rhs->name();
}

void test1(const SimpleNode* a, const SimpleNode* b, const SimpleNode* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(const SimpleNode* a, const SimpleNode* b, const SimpleNode* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(const SimpleNode* a, const SimpleNode* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a)) 
    SymmetryChecker();
}

void test3_2(const SimpleNode* a, const SimpleNode* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a)) 
    SymmetryChecker();
}

void test4(const SimpleNode* a) {
  NewTest();
  if (lambda0(a, a)) 
    ReflexivityChecker();
}
