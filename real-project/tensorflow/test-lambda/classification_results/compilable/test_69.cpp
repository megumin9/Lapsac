#include <bits/stdc++.h>
using namespace std;

struct SignatureDefParam {
    string name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const SignatureDefParam& x, const SignatureDefParam& y) {
  return x.name() < y.name();
}

void test1(SignatureDefParam a, SignatureDefParam b, SignatureDefParam c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(SignatureDefParam a, SignatureDefParam b, SignatureDefParam c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(SignatureDefParam a, SignatureDefParam b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(SignatureDefParam a, SignatureDefParam b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(SignatureDefParam a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}