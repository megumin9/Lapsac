#include <bits/stdc++.h>

struct IndexMaskSegment {
    int size() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda3(const IndexMaskSegment &a, const IndexMaskSegment &b) {
  return a.size() < b.size();
}

void test1(const IndexMaskSegment &a, const IndexMaskSegment &b, const IndexMaskSegment &c) {
  NewTest();
  if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c))
    ConsistencyChecker();
}

void test2(const IndexMaskSegment &a, const IndexMaskSegment &b, const IndexMaskSegment &c) {
  NewTest();
  if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a))
    TransiveChecker();
}

void test3_1(const IndexMaskSegment &a, const IndexMaskSegment &b) {
  NewTest();
  if (lambda3(a,b) && lambda3(b,a))
    SymmetryChecker();
}

void test4(const IndexMaskSegment &a) {
  NewTest();
  if (lambda3(a,a))
    ReflexivityChecker();
}