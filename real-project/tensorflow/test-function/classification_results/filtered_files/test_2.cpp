#include <bits/stdc++.h>
struct WeightedDelta { int delta; };
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int WeightedDeltaCompare(const void* const a, const void* const b) {
  return (reinterpret_cast<const WeightedDelta*>(a)->delta -
          reinterpret_cast<const WeightedDelta*>(b)->delta) <= 0 ? 1 : -1;
}

void test1(const void* a, const void* b, const void* c) {
  NewTest();
  if (!(WeightedDeltaCompare(a, b) < 0) && 
      !(WeightedDeltaCompare(b, c) < 0) && 
      (WeightedDeltaCompare(a, c) < 0)) {
    ConsistencyChecker();
  }
}

void test2(const void* a, const void* b, const void* c) {
  NewTest();
  if ((WeightedDeltaCompare(a, b) < 0) && 
      (WeightedDeltaCompare(b, c) < 0) && 
      (WeightedDeltaCompare(c, a) < 0)) {
    TransiveChecker();
  }
}

void test3_1(const void* a, const void* b) {
  NewTest();
  if ((WeightedDeltaCompare(a, b) < 0) && (WeightedDeltaCompare(b, a) < 0)) {
    SymmetryChecker();
  }
}

void test3_2(const void* a, const void* b) {
  NewTest();
  if ((WeightedDeltaCompare(a, b) > 0) && (WeightedDeltaCompare(b, a) > 0)) {
    SymmetryChecker();
  }
}

void test4(const void* a) {
  NewTest();
  if (WeightedDeltaCompare(a, a) < 0 || WeightedDeltaCompare(a, a) > 0) {
    ReflexivityChecker();
  }
}