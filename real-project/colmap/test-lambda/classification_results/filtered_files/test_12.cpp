#include <bits/stdc++.h>
struct VlCovDetFeature {
    int o;
    int s;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const VlCovDetFeature& feature1, const VlCovDetFeature& feature2) {
  if (feature1.o == feature2.o) {
    return feature1.s > feature2.s;
  } else {
    return feature1.o > feature2.o;
  }
}

void test1(const VlCovDetFeature& a, const VlCovDetFeature& b, const VlCovDetFeature& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const VlCovDetFeature& a, const VlCovDetFeature& b, const VlCovDetFeature& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const VlCovDetFeature& a, const VlCovDetFeature& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const VlCovDetFeature& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}