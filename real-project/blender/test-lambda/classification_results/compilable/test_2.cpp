#include <bits/stdc++.h>
using namespace std;

struct DrawPrototype {
    int group_id;
    int res_handle;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const DrawPrototype &a, const DrawPrototype &b) {
  return (a.group_id < b.group_id) ||
         (a.group_id == b.group_id && a.res_handle > b.res_handle);
}

void test1(const DrawPrototype &a, const DrawPrototype &b, const DrawPrototype &c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const DrawPrototype &a, const DrawPrototype &b, const DrawPrototype &c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const DrawPrototype &a, const DrawPrototype &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const DrawPrototype &a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}