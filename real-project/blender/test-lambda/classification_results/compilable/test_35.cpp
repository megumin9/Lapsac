#include <bits/stdc++.h>
using namespace std;

struct IndexMaskSegment {
    int size() const { return 0; }
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const IndexMaskSegment &a, const IndexMaskSegment &b) {
  return a.size() < b.size();
}

void test1(IndexMaskSegment a, IndexMaskSegment b, IndexMaskSegment c) {
  NewTest();
  if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c)) 
    ConsistencyChecker();
}

void test2(IndexMaskSegment a, IndexMaskSegment b, IndexMaskSegment c) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a)) 
    TransiveChecker();
}

void test3_1(IndexMaskSegment a, IndexMaskSegment b) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(IndexMaskSegment a) {
  NewTest();
  if (lambda2(a, a)) 
    ReflexivityChecker();
}