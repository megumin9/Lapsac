#include <bits/stdc++.h>
using namespace std;

struct BVHTreeOverlap {
    int indexA;
    int indexB;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool bvhtreeverlap_cmp(const BVHTreeOverlap &a, const BVHTreeOverlap &b) {
  if (a.indexA < b.indexA) {
    return true;
  }
  if ((a.indexA == b.indexA) && (a.indexB < b.indexB)) {
    return true;
  }
  return false;
}

void test1(BVHTreeOverlap a, BVHTreeOverlap b, BVHTreeOverlap c) {
  NewTest();
  if (!bvhtreeverlap_cmp(a, b) && !bvhtreeverlap_cmp(b, c) && bvhtreeverlap_cmp(a, c))
    ConsistencyChecker();
}

void test2(BVHTreeOverlap a, BVHTreeOverlap b, BVHTreeOverlap c) {
  NewTest();
  if (bvhtreeverlap_cmp(a, b) && bvhtreeverlap_cmp(b, c) && bvhtreeverlap_cmp(c, a))
    TransiveChecker();
}

void test3_1(BVHTreeOverlap a, BVHTreeOverlap b) {
  NewTest();
  if (bvhtreeverlap_cmp(a, b) && bvhtreeverlap_cmp(b, a))
    SymmetryChecker();
}

void test4(BVHTreeOverlap a) {
  NewTest();
  if (bvhtreeverlap_cmp(a, a))
    ReflexivityChecker();
}