#include <bits/stdc++.h>
struct testclass {
    bool var5;
    int var1;
    int var2;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(testclass *a, testclass *b) {
  if (a->var5)
    return true;

  if (b->var5)
    return false;

  return a->var1 < b->var2;
}

void test1(testclass *a, testclass *b, testclass *c) {
  NewTest();
  if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
    ConsistencyChecker();
}

void test2(testclass *a, testclass *b, testclass *c) {
  NewTest();
  if (cmp(a,b) && cmp(b,c) && cmp(c,a))
    TransiveChecker();
}

void test3_1(testclass *a, testclass *b) {
  NewTest();
  if (cmp(a,b) && cmp(b,a))
    SymmetryChecker();
}

void test3_2(testclass *a, testclass *b) {
  NewTest();
  if (cmp(a,b) && cmp(b,a))
    SymmetryChecker();
}

void test4(testclass *a) {
  NewTest();
  if (cmp(a, a))
    ReflexivityChecker();
}