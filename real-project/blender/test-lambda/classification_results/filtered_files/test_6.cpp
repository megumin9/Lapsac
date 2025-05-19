#include <bits/stdc++.h>

struct ObjectInfo {
    int depth;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ObjectInfo &info1, const ObjectInfo &info2) {
  return info1.depth < info2.depth;
}

void test1(ObjectInfo a, ObjectInfo b, ObjectInfo c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
    ConsistencyChecker();
}

void test2(ObjectInfo a, ObjectInfo b, ObjectInfo c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
    TransiveChecker();
}

void test3_1(ObjectInfo a, ObjectInfo b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test3_2(ObjectInfo a, ObjectInfo b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test4(ObjectInfo a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}