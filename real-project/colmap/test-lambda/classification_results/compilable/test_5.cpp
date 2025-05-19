#include <bits/stdc++.h>
using namespace std;

vector<pair<int, vector<int>>> matches_;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const size_t idx1, const size_t idx2) {
  return matches_[idx1].second.size() > matches_[idx2].second.size();
}

void test1(size_t a, size_t b, size_t c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(size_t a, size_t b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(size_t a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}