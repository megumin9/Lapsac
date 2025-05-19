#include <bits/stdc++.h>
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_int(const void *av, const void *bv) {
  const int *a = (int *)av;
  const int *b = (int *)bv;
  return *a - *b;
}

void test1(int a, int b, int c) {
  NewTest();
  if (!(compare_int(&a, &b) < 0) && !(compare_int(&b, &c) < 0) && (compare_int(&a, &c) < 0))
    ConsistencyChecker();
}

void test2(int a, int b, int c) {
  NewTest();
  if ((compare_int(&a, &b) < 0) && (compare_int(&b, &c) < 0) && (compare_int(&c, &a) < 0))
    TransiveChecker();
}

void test3_2(int a, int b) {
  NewTest();
  if ((compare_int(&a, &b) < 0) && (compare_int(&b, &a) < 0))
    SymmetryChecker();
}

void test4(int a) {
  NewTest();
  if (compare_int(&a, &a) < 0 || compare_int(&a, &a) > 0)
    ReflexivityChecker();
}