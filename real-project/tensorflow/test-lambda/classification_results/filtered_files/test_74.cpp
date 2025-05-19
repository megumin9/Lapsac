#include <bits/stdc++.h>
using namespace std;

struct PR {
    int r;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const PR& a, const PR& b) {
  return a.r < b.r;
}

void test1(const PR& a, const PR& b, const PR& c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
    ConsistencyChecker();
  }
}

void test2(const PR& a, const PR& b, const PR& c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
    TransiveChecker();
  }
}

void test3_1(const PR& a, const PR& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(const PR& a, const PR& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test4(const PR& a) {
  NewTest();
  if (lambda0(a, a)) {
    ReflexivityChecker();
  }
}