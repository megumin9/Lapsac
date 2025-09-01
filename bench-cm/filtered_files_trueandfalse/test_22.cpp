#include <bits/stdc++.h>

struct SweepLineEvent {
    int xValue;
    int eventType;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_28(const SweepLineEvent *f, const SweepLineEvent *s) {
  if (f->xValue < s->xValue) return true;
  if (f->eventType < s->eventType) return true;
  return false;
}

void test1(const SweepLineEvent* a, const SweepLineEvent* b, const SweepLineEvent* c){
  NewTest();
  if (!compare_28(a,b) && !compare_28(b,c) && compare_28(a,c)) 
    ConsistencyChecker();
}

void test2(const SweepLineEvent* a, const SweepLineEvent* b, const SweepLineEvent* c){
  NewTest();
  if (compare_28(a,b) && compare_28(b,c) && compare_28(c,a)) 
    TransiveChecker();
}

void test3_1(const SweepLineEvent* a, const SweepLineEvent* b){
  NewTest();
  if (compare_28(a,b) && compare_28(b,a))
    SymmetryChecker();
}

void test3_2(const SweepLineEvent* a, const SweepLineEvent* b){
  NewTest();
  if (compare_28(a,b) && compare_28(b,a))
    SymmetryChecker();
}

void test4(const SweepLineEvent* a){
  NewTest();
  if (compare_28(a, a)) 
    ReflexivityChecker();
}