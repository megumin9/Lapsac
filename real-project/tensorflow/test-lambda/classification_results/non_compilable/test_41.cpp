#include <map>
#include "tensorflow/core/platform/status.h"

namespace mlir {
namespace TF {
class DTensorAllReduceOp;
} // namespace TF
} // namespace mlir

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

std::map<mlir::TF::DTensorAllReduceOp, int> all_reduce_topo;
tensorflow::Status status;

bool lambda1(mlir::TF::DTensorAllReduceOp& lhs, mlir::TF::DTensorAllReduceOp& rhs) {
  if ((all_reduce_topo.find(lhs) == all_reduce_topo.end()) ||
      (all_reduce_topo.find(rhs) == all_reduce_topo.end())) {
    status = tensorflow::errors::Internal(
        "Error: encounter AllReduce op with no topological level assignment.");
    return false;
  }
  return all_reduce_topo[lhs] < all_reduce_topo[rhs];
}

void test1(mlir::TF::DTensorAllReduceOp& a, mlir::TF::DTensorAllReduceOp& b, mlir::TF::DTensorAllReduceOp& c) {
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(mlir::TF::DTensorAllReduceOp& a, mlir::TF::DTensorAllReduceOp& b, mlir::TF::DTensorAllReduceOp& c) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(mlir::TF::DTensorAllReduceOp& a, mlir::TF::DTensorAllReduceOp& b) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(mlir::TF::DTensorAllReduceOp& a) {
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}