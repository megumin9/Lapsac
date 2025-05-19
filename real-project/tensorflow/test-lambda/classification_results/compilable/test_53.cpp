
#include <bits/stdc++.h>
using namespace std;

struct Node;
extern map<Node*, int> node_to_position;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(Node* a, Node* b) {
  return node_to_position[a] < node_to_position[b];
}

void test1(Node* a, Node* b, Node* c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
    ConsistencyChecker();
  }
}

void test2(Node* a, Node* b, Node* c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
    TransiveChecker();
  }
}

void test3_1(Node* a, Node* b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(Node* a, Node* b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test4(Node* a) {
  NewTest();
  if (lambda0(a, a)) {
    ReflexivityChecker();
  }
}
