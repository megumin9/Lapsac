#include <bits/stdc++.h>

struct Node {
    std::string name() const;
};

struct NodeAndOutput {
    Node* first;
    int second;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<NodeAndOutput, NodeAndOutput>& n1,
             const std::pair<NodeAndOutput, NodeAndOutput>& n2) {
  return std::make_tuple(n1.first.first->name(), n1.first.second) < 
         std::make_tuple(n2.first.first->name(), n2.first.second);
}

void test1(std::pair<NodeAndOutput, NodeAndOutput> a,
           std::pair<NodeAndOutput, NodeAndOutput> b,
           std::pair<NodeAndOutput, NodeAndOutput> c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(std::pair<NodeAndOutput, NodeAndOutput> a,
           std::pair<NodeAndOutput, NodeAndOutput> b,
           std::pair<NodeAndOutput, NodeAndOutput> c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(std::pair<NodeAndOutput, NodeAndOutput> a,
             std::pair<NodeAndOutput, NodeAndOutput> b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(std::pair<NodeAndOutput, NodeAndOutput> a,
             std::pair<NodeAndOutput, NodeAndOutput> b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(std::pair<NodeAndOutput, NodeAndOutput> a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}