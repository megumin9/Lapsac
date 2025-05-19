#include <bits/stdc++.h>

struct freqType {
    int value;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int freqCompare(const void *A, const void *B) {
   const freqType *a = (const freqType *) A;
   const freqType *b = (const freqType *) B;

   if (a->value < b->value)
      return -1;
   if (a->value > b->value)
      return 1;
   return 0;
}

void test1(const freqType* a, const freqType* b, const freqType* c) {
   NewTest();
   if (!(freqCompare(a, b) < 0) && !(freqCompare(b, c) < 0) && (freqCompare(a, c) < 0))
      ConsistencyChecker();
}

void test2(const freqType* a, const freqType* b, const freqType* c) {
   NewTest();
   if ((freqCompare(a, b) < 0) && (freqCompare(b, c) < 0) && (freqCompare(c, a) < 0))
      TransiveChecker();
}

void test3_1(const freqType* a, const freqType* b) {
   NewTest();
   if ((freqCompare(a, b) > 0) && (freqCompare(b, a) > 0))
      SymmetryChecker();
}

void test3_2(const freqType* a, const freqType* b) {
   NewTest();
   if ((freqCompare(a, b) < 0) && (freqCompare(b, a) < 0))
      SymmetryChecker();
}

void test4(const freqType* a) {
   NewTest();
   if (freqCompare(a, a) < 0 || freqCompare(a, a) > 0)
      ReflexivityChecker();
}