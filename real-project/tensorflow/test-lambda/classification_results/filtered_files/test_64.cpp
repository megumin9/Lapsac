#include <bits/stdc++.h>
using namespace std;

class XlaResource {
public:
    int arg_num() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const XlaResource* a, const XlaResource* b) {
  return a->arg_num() < b->arg_num();
}

void test1(const XlaResource* a, const XlaResource* b, const XlaResource* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const XlaResource* a, const XlaResource* b, const XlaResource* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const XlaResource* a, const XlaResource* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const XlaResource* a, const XlaResource* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const XlaResource* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}