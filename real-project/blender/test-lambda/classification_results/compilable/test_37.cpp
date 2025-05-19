#include <bits/stdc++.h>
using namespace std;

struct IndexMaskSegment {
  int size() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda4(const IndexMaskSegment &a, const IndexMaskSegment &b) {
  return a.size() > b.size();
}

void test1(const IndexMaskSegment &a, const IndexMaskSegment &b, const IndexMaskSegment &c) {
  NewTest();
  if (!lambda4(a,b) && !lambda4(b,c) && lambda4(a,c))
    ConsistencyChecker();
}

void test2(const IndexMaskSegment &a, const IndexMaskSegment &b, const IndexMaskSegment &c) {
  NewTest();
  if (lambda4(a,b) && lambda4(b,c) && lambda4(c,a))
    TransiveChecker();
}

void test3_1(const IndexMaskSegment &a, const IndexMaskSegment &b) {
  NewTest();
  if (lambda4(a,b) && lambda4(b,a))
    SymmetryChecker();
}

void test3_2(const IndexMaskSegment &a, const IndexMaskSegment &b) {
  NewTest();
  if (lambda4(a,b) && lambda4(b,a))
    SymmetryChecker();
}

void test4(const IndexMaskSegment &a) {
  NewTest();
  if (lambda4(a, a))
    ReflexivityChecker();
}