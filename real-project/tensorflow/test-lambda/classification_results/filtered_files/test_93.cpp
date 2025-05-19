#include <bits/stdc++.h>
using namespace std;

struct Value;
struct Operation;
struct Block;
struct BroadcastIntent;

struct Value {
    Operation* getDefiningOp() const;
};

struct Operation {
    Block* getBlock();
    bool isBeforeInBlock(Operation* other);
};

struct Block {};

struct BroadcastIntent {
    Value targetValue;
};

Block* parentBlock;
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const BroadcastIntent &a, const BroadcastIntent &b) {
  Operation *producerOpA = a.targetValue.getDefiningOp();
  Operation *producerOpB = b.targetValue.getDefiningOp();
  bool aInBlock = producerOpA != nullptr && 
                  producerOpA->getBlock() == parentBlock;
  bool bInBlock = producerOpB != nullptr &&
                  producerOpB->getBlock() == parentBlock;
  if (aInBlock && bInBlock) {
    return producerOpA->isBeforeInBlock(producerOpB);
  }
  return !aInBlock && bInBlock;
}

void test1(BroadcastIntent &a, BroadcastIntent &b, BroadcastIntent &c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(BroadcastIntent &a, BroadcastIntent &b, BroadcastIntent &c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(BroadcastIntent &a, BroadcastIntent &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(BroadcastIntent &a, BroadcastIntent &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(BroadcastIntent &a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}