#include <bits/stdc++.h>

struct KernelDef {
    int op() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const KernelDef* a, const KernelDef* b) {
  return a->op() < b->op();
}

void test1(const KernelDef* a, const KernelDef* b, const KernelDef* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const KernelDef* a, const KernelDef* b, const KernelDef* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const KernelDef* a, const KernelDef* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const KernelDef* a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}