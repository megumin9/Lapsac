
#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();
float** points;

bool lambda0(const int &a_index, const int &b_index) {
    const float *a = points[a_index];
    const float *b = points[b_index];
    if (a[1] > b[1]) {
      return false;
    }
    if (a[1] < b[1]) {
      return true;
    }

    if (a[0] > b[0]) {
      return false;
    }
    if (a[0] < b[0]) {
      return true;
    }
    return false;
}

void test1(int a, int b, int c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
    ConsistencyChecker();
  }
}

void test2(int a, int b, int c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
    TransiveChecker();
  }
}

void test3_1(int a, int b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(int a, int b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test4(int a) {
  NewTest();
  if (lambda0(a, a)) {
    ReflexivityChecker();
  }
}
