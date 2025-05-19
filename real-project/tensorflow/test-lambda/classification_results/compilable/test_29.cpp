#include <bits/stdc++.h>
using namespace std;

struct ParsedName {
    int task;
};

struct Device {
    ParsedName parsed_name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(Device* i, Device* j) {
  return i->parsed_name().task < j->parsed_name().task;
}

void test1(Device* a, Device* b, Device* c) {
  NewTest();
  if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(Device* a, Device* b, Device* c) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(Device* a, Device* b) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test3_2(Device* a, Device* b) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(Device* a) {
  NewTest();
  if (lambda2(a,a))
    ReflexivityChecker();
}