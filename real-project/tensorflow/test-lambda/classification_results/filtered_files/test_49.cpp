#include <bits/stdc++.h>
using namespace std;

struct ParsedDevice {
    int id;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const ParsedDevice& i, const ParsedDevice& j) {
  return i.id < j.id;
}

void test1(const ParsedDevice& a, const ParsedDevice& b, const ParsedDevice& c) {
  NewTest();
  if (!lambda1(a, b) && !lambda1(b, c) && lambda1(a, c))
    ConsistencyChecker();
}

void test2(const ParsedDevice& a, const ParsedDevice& b, const ParsedDevice& c) {
  NewTest();
  if (lambda1(a, b) && lambda1(b, c) && lambda1(c, a))
    TransiveChecker();
}

void test3_1(const ParsedDevice& a, const ParsedDevice& b) {
  NewTest();
  if (lambda1(a, b) && lambda1(b, a))
    SymmetryChecker();
}

void test4(const ParsedDevice& a) {
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}