#include <bits/stdc++.h>

namespace mlir {
class Block;
namespace TF {

class DTensorAllReduceOp_;

using DTensorAllReduceOp = DTensorAllReduceOp_*;

class DTensorAllReduceOp_ {
public:
  ::mlir::Block* getBlock() const;
  bool isBeforeInBlock(DTensorAllReduceOp_* other) const;
};

} // namespace TF
} // namespace mlir

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(std::vector<mlir::TF::DTensorAllReduceOp> lhs,
             std::vector<mlir::TF::DTensorAllReduceOp> rhs) {
  if (lhs.empty() && !rhs.empty()) return false;
  if (!lhs.empty() && rhs.empty()) return true;
  if (lhs[0]->getBlock() != rhs[0]->getBlock()) {
    return lhs[0]->getBlock() < rhs[0]->getBlock();
  }
  return lhs[0]->isBeforeInBlock(rhs[0]);
}

void test1(std::vector<mlir::TF::DTensorAllReduceOp> a,
           std::vector<mlir::TF::DTensorAllReduceOp> b,
           std::vector<mlir::TF::DTensorAllReduceOp> c) {
  NewTest();
  if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(std::vector<mlir::TF::DTensorAllReduceOp> a,
           std::vector<mlir::TF::DTensorAllReduceOp> b,
           std::vector<mlir::TF::DTensorAllReduceOp> c) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(std::vector<mlir::TF::DTensorAllReduceOp> a,
             std::vector<mlir::TF::DTensorAllReduceOp> b) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(std::vector<mlir::TF::DTensorAllReduceOp> a) {
  NewTest();
  if (lambda2(a,a))
    ReflexivityChecker();
}