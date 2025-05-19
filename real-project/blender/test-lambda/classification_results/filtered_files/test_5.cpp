#include <bits/stdc++.h>
using namespace std;

struct MTLMaterial {
    string name;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const MTLMaterial &a, const MTLMaterial &b) {
  return a.name < b.name;
}

void test1(const MTLMaterial &a, const MTLMaterial &b, const MTLMaterial &c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const MTLMaterial &a, const MTLMaterial &b, const MTLMaterial &c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const MTLMaterial &a, const MTLMaterial &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const MTLMaterial &a, const MTLMaterial &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const MTLMaterial &a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}