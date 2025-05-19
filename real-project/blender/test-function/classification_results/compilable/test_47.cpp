#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();
int testsort_array_str_cmp(const void *a, const void *b);

int testsort_array_str_cmp_reverse(const void *a, const void *b) {
  return -testsort_array_str_cmp(a, b);
}

void test1(const void *a, const void *b, const void *c) {
  NewTest();
  if (!(testsort_array_str_cmp_reverse(a,b)<0) && 
      !(testsort_array_str_cmp_reverse(b,c)<0) && 
      (testsort_array_str_cmp_reverse(a,c)<0)) {
    ConsistencyChecker();
  }
}

void test2(const void *a, const void *b, const void *c) {
  NewTest();
  if ((testsort_array_str_cmp_reverse(a,b)<0) && 
      (testsort_array_str_cmp_reverse(b,c)<0) && 
      (testsort_array_str_cmp_reverse(c,a)<0)) {
    TransiveChecker();
  }
}

void test3_1(const void *a, const void *b) {
  NewTest();
  if ((testsort_array_str_cmp_reverse(a,b)>0) && 
      (testsort_array_str_cmp_reverse(b,a)>0)) {
    SymmetryChecker();
  }
}

void test3_2(const void *a, const void *b) {
  NewTest();
  if ((testsort_array_str_cmp_reverse(a,b)<0) && 
      (testsort_array_str_cmp_reverse(b,a)<0)) {
    SymmetryChecker();
  }
}

void test4(const void *a) {
  NewTest();
  if (testsort_array_str_cmp_reverse(a,a) != 0) {
    ReflexivityChecker();
  }
}