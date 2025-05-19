#include <bits/stdc++.h>
#include <tuple>
using NotConvertedOPTuple = std::tuple<int, int>;
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const NotConvertedOPTuple& a, const NotConvertedOPTuple& b) {
  return std::get<1>(a) > std::get<1>(b);
}

void test1(const NotConvertedOPTuple& a, const NotConvertedOPTuple& b, const NotConvertedOPTuple& c) {
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const NotConvertedOPTuple& a, const NotConvertedOPTuple& b, const NotConvertedOPTuple& c) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const NotConvertedOPTuple& a, const NotConvertedOPTuple& b) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const NotConvertedOPTuple& a) {
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}