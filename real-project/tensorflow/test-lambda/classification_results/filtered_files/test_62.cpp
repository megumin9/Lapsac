#include <bits/stdc++.h>
using namespace std;

struct Node {};
struct WhileLoopArg { Node enter; };

struct NodeCmpByNameResourcesLast {
    bool operator()(const Node&, const Node&) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const WhileLoopArg& a, const WhileLoopArg& b) {
  return NodeCmpByNameResourcesLast()(a.enter, b.enter);
}

void test1(WhileLoopArg a, WhileLoopArg b, WhileLoopArg c) {
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(WhileLoopArg a, WhileLoopArg b, WhileLoopArg c) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(WhileLoopArg a, WhileLoopArg b) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(WhileLoopArg a) {
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}