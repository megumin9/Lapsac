#include <bits/stdc++.h>
using namespace std;

struct IndexSize {
    int size;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const IndexSize& a, const IndexSize& b) {
  return a.size > b.size;
}

void test1(const IndexSize& a, const IndexSize& b, const IndexSize& c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) 
    ConsistencyChecker();
}

void test2(const IndexSize& a, const IndexSize& b, const IndexSize& c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) 
    TransiveChecker();
}

void test3_1(const IndexSize& a, const IndexSize& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) 
    SymmetryChecker();
}

void test3_2(const IndexSize& a, const IndexSize& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) 
    SymmetryChecker();
}

void test4(const IndexSize& a) {
  NewTest();
  if (lambda0(a, a)) 
    ReflexivityChecker();
}