#include <bits/stdc++.h>
using namespace std;

struct ParsedName {
    int replica;
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

bool lambda0(Device* i, Device* j) {
  ParsedName i_name = i->parsed_name();
  ParsedName j_name = j->parsed_name();
  if (i_name.replica != j_name.replica) {
    return i_name.replica < j_name.replica;
  }
  return i_name.task < j_name.task;
}

void test1(Device* a, Device* b, Device* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(Device* a, Device* b, Device* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(Device* a, Device* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(Device* a, Device* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(Device* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}