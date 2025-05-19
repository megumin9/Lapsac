#include <bits/stdc++.h>
struct TensorShapeProto;
bool CompareSymbolicallyShapedTensorSizes(const TensorShapeProto& left, const TensorShapeProto& right);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const TensorShapeProto& left, const TensorShapeProto& right) {
  return CompareSymbolicallyShapedTensorSizes(left, right);
}

void test1(const TensorShapeProto& a, const TensorShapeProto& b, const TensorShapeProto& c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
    ConsistencyChecker();
  }
}

void test2(const TensorShapeProto& a, const TensorShapeProto& b, const TensorShapeProto& c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
    TransiveChecker();
  }
}

void test3_1(const TensorShapeProto& a, const TensorShapeProto& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(const TensorShapeProto& a, const TensorShapeProto& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test4(const TensorShapeProto& a) {
  NewTest();
  if (lambda0(a, a)) {
    ReflexivityChecker();
  }
}