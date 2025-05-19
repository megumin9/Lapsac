#include <bits/stdc++.h>

struct EvaluatedSegment {
    struct Bounds {
        int start() const { return 0; }
    } bounds;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda5(const EvaluatedSegment &a, const EvaluatedSegment &b) {
  return a.bounds.start() < b.bounds.start();
}

void test1(const EvaluatedSegment &a, const EvaluatedSegment &b, const EvaluatedSegment &c) {
  NewTest();
  if (!lambda5(a,b) && !lambda5(b,c) && lambda5(a,c))
    ConsistencyChecker();
}

void test2(const EvaluatedSegment &a, const EvaluatedSegment &b, const EvaluatedSegment &c) {
  NewTest();
  if (lambda5(a,b) && lambda5(b,c) && lambda5(c,a))
    TransiveChecker();
}

void test3_1(const EvaluatedSegment &a, const EvaluatedSegment &b) {
  NewTest();
  if (lambda5(a,b) && lambda5(b,a))
    SymmetryChecker();
}

void test3_2(const EvaluatedSegment &a, const EvaluatedSegment &b) {
  NewTest();
  if (lambda5(a,b) && lambda5(b,a))
    SymmetryChecker();
}

void test4(const EvaluatedSegment &a) {
  NewTest();
  if (lambda5(a, a))
    ReflexivityChecker();
}