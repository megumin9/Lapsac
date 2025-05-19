#include <bits/stdc++.h>
using namespace std;

struct ParsedDevice {
    int task;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ParsedDevice& a, const ParsedDevice& b) {
  return a.task < b.task;
}

void test1(const ParsedDevice& a, const ParsedDevice& b, const ParsedDevice& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const ParsedDevice& a, const ParsedDevice& b, const ParsedDevice& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const ParsedDevice& a, const ParsedDevice& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const ParsedDevice& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}