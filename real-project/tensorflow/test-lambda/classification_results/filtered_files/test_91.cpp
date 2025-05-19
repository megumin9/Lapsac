#include <bits/stdc++.h>
class XPlane {
public:
    int id() const;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const XPlane* a, const XPlane* b) {
  return a->id() < b->id();
}

void test1(const XPlane* a, const XPlane* b, const XPlane* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const XPlane* a, const XPlane* b, const XPlane* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const XPlane* a, const XPlane* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const XPlane* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}