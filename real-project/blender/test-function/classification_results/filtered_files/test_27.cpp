#include <bits/stdc++.h>
using namespace std;

struct KnifeLineHit {
    int l;
    int m;
    int v;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int linehit_compare(const KnifeLineHit &lh1, const KnifeLineHit &lh2) {
  if (lh1.l < lh2.l) {
    return 1;
  }
  if (lh1.l > lh2.l) {
    return 0;
  }
  if (lh1.m < lh2.m) {
    return 1;
  }
  if (lh1.m > lh2.m) {
    return 0;
  }
  if (lh1.v < lh2.v) {
    return 1;
  }
  if (lh1.v > lh2.v) {
    return 0;
  }
  return 0;
}

void test1(KnifeLineHit a, KnifeLineHit b, KnifeLineHit c) {
    NewTest();
    if (!(linehit_compare(a, b) < 0) && !(linehit_compare(b, c) < 0) && (linehit_compare(a, c) < 0)) {
        ConsistencyChecker();
    }
}

void test2(KnifeLineHit a, KnifeLineHit b, KnifeLineHit c) {
    NewTest();
    if ((linehit_compare(a, b) < 0) && (linehit_compare(b, c) < 0) && (linehit_compare(c, a) < 0)) {
        TransiveChecker();
    }
}

void test3_1(KnifeLineHit a, KnifeLineHit b) {
    NewTest();
    if ((linehit_compare(a, b) < 0) && (linehit_compare(b, a) < 0)) {
        SymmetryChecker();
    }
}

void test3_2(KnifeLineHit a, KnifeLineHit b) {
    NewTest();
    if ((linehit_compare(a, b) > 0) && (linehit_compare(b, a) > 0)) {
        SymmetryChecker();
    }
}

void test4(KnifeLineHit a) {
    NewTest();
    if (linehit_compare(a, a) < 0 || linehit_compare(a, a) > 0) {
        ReflexivityChecker();
    }
}