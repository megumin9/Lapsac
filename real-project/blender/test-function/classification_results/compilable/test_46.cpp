#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int testsort_array_str_cmp(const void *a, const void *b) {
  int i = strcmp(*(const char **)a, *(const char **)b);
  return (i > 0) ? 1 : (i < 0) ? -1 : 0;
}

void test1(const void *a, const void *b, const void *c) {
  NewTest();
  if (!(testsort_array_str_cmp(a, b) < 0) && 
      !(testsort_array_str_cmp(b, c) < 0) && 
      (testsort_array_str_cmp(a, c) < 0)) {
    ConsistencyChecker();
  }
}

void test2(const void *a, const void *b, const void *c) {
  NewTest();
  if ((testsort_array_str_cmp(a, b) < 0) && 
      (testsort_array_str_cmp(b, c) < 0) && 
      (testsort_array_str_cmp(c, a) < 0)) {
    TransiveChecker();
  }
}

void test3_1(const void *a, const void *b) {
  NewTest();
  if ((testsort_array_str_cmp(a, b) > 0) && 
      (testsort_array_str_cmp(b, a) > 0)) {
    SymmetryChecker();
  }
}

void test3_2(const void *a, const void *b) {
  NewTest();
  if ((testsort_array_str_cmp(a, b) < 0) && 
      (testsort_array_str_cmp(b, a) < 0)) {
    SymmetryChecker();
  }
}

void test4(const void *a) {
  NewTest();
  if (testsort_array_str_cmp(a, a) < 0 || 
      testsort_array_str_cmp(a, a) > 0) {
    ReflexivityChecker();
  }
}