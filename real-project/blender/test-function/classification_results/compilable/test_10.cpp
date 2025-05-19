#include <bits/stdc++.h>
using uint = unsigned int;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int uint_compare(const void *a_v, const void *b_v) {
  const uint *a = static_cast<const uint *>(a_v);
  const uint *b = static_cast<const uint *>(b_v);
  return *a < *b;
}

void test1(const uint *a, const uint *b, const uint *c) {
  NewTest();
  if (!(uint_compare(a, b) < 0) && !(uint_compare(b, c) < 0) && (uint_compare(a, c) < 0)) {
    ConsistencyChecker();
  }
}

void test2(const uint *a, const uint *b, const uint *c) {
  NewTest();
  if ((uint_compare(a, b) < 0) && (uint_compare(b, c) < 0) && (uint_compare(c, a) < 0)) {
    TransiveChecker();
  }
}

void test3_2(const uint *a, const uint *b) {
  NewTest();
  if ((uint_compare(a, b) < 0) && (uint_compare(b, a) < 0)) {
    SymmetryChecker();
  }
}

void test4(const uint *a) {
  NewTest();
  if (uint_compare(a, a) < 0 || uint_compare(a, a) > 0) {
    ReflexivityChecker();
  }
}