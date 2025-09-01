#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    virtual ~Node() = default;
};

class BasicBlock : public Node {
public:
    int getsize() const { return 0; }
};

using EdgeWeight = pair<pair<const Node*, const Node*>, int>;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_35(EdgeWeight X, EdgeWeight Y) {
  if (X.second > Y.second) return true;
  if (X.second < Y.second) return false;

  const BasicBlock *BBX_1 = dynamic_cast<const BasicBlock*>(X.first.first);
  const BasicBlock *BBY_1 = dynamic_cast<const BasicBlock*>(Y.first.first);
  if (BBX_1->getsize() > BBY_1->getsize()) return true;
  if (BBX_1->getsize() < BBY_1->getsize()) return false;

  const BasicBlock *BBX_2 = dynamic_cast<const BasicBlock*>(X.first.second);
  const BasicBlock *BBY_2 = dynamic_cast<const BasicBlock*>(Y.first.second);
  if (BBX_2->getsize() > BBY_2->getsize()) return true;
  if (BBX_2->getsize() < BBY_2->getsize()) return false;

  return false;
}

void test1(EdgeWeight a, EdgeWeight b, EdgeWeight c) {
  NewTest();
  if (!compare_35(a, b) && !compare_35(b, c) && compare_35(a, c))
    ConsistencyChecker();
}

void test2(EdgeWeight a, EdgeWeight b, EdgeWeight c) {
  NewTest();
  if (compare_35(a, b) && compare_35(b, c) && compare_35(c, a))
    TransiveChecker();
}

void test3_1(EdgeWeight a, EdgeWeight b) {
  NewTest();
  if (compare_35(a, b) && compare_35(b, a))
    SymmetryChecker();
}

void test3_2(EdgeWeight a, EdgeWeight b) {
  NewTest();
  if (compare_35(a, b) && compare_35(b, a))
    SymmetryChecker();
}

void test4(EdgeWeight a) {
  NewTest();
  if (compare_35(a, a))
    ReflexivityChecker();
}