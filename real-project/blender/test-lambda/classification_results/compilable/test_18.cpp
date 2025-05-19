
#include <bits/stdc++.h>

struct SegmentCircleIntersection {
    int factor;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(SegmentCircleIntersection a, SegmentCircleIntersection b) {
  return a.factor < b.factor;
}

void test1(SegmentCircleIntersection a, SegmentCircleIntersection b, SegmentCircleIntersection c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(SegmentCircleIntersection a, SegmentCircleIntersection b, SegmentCircleIntersection c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(SegmentCircleIntersection a, SegmentCircleIntersection b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(SegmentCircleIntersection a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}
