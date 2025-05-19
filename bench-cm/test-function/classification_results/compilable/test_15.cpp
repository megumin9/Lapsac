#include <bits/stdc++.h>

class Node {
public:
    virtual ~Node() = default;
};

class BasicBlock : public Node {
public:
    int getsize() const;
};

using EdgeWeight = std::pair<std::pair<Node*, Node*>, int>;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_35(EdgeWeight X, EdgeWeight Y) {
  if (X.second > Y.second) return true;
  if (X.second < Y.second) return false;

  if (const BasicBlock *BBX = dynamic_cast<const BasicBlock*>(X.first.first)) {
    if (const BasicBlock *BBY = dynamic_cast<const BasicBlock*>(Y.first.first)) {
      if (BBX->getsize() > BBY->getsize()) return true;
      if (BBX->getsize() < BBY->getsize()) return false;
    }
  }

  if (const BasicBlock *BBX = dynamic_cast<const BasicBlock*>(X.first.second)) {
    if (const BasicBlock *BBY = dynamic_cast<const BasicBlock*>(Y.first.second)) {
      if (BBX->getsize() > BBY->getsize()) return true;
      if (BBX->getsize() < BBY->getsize()) return false;
    }
  }

  return false;
}

void test1(EdgeWeight a, EdgeWeight b, EdgeWeight c) {
  NewTest();
  if (!compare_35(a,b) && !compare_35(b,c) && compare_35(a,c))
    ConsistencyChecker();
}

void test2(EdgeWeight a, EdgeWeight b, EdgeWeight c) {
  NewTest();
  if (compare_35(a,b) && compare_35(b,c) && compare_35(c,a))
    TransiveChecker();
}

void test3_1(EdgeWeight a, EdgeWeight b) {
  NewTest();
  if (compare_35(a,b) && compare_35(b,a))
    SymmetryChecker();
}

void test3_2(EdgeWeight a, EdgeWeight b) {
  NewTest();
  if (compare_35(a,b) && compare_35(b,a))
    SymmetryChecker();
}

void test4(EdgeWeight a) {
  NewTest();
  if (compare_35(a, a))
    ReflexivityChecker();
}