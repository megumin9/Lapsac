#include <bits/stdc++.h>

struct HeapObject {
    int logical_buffer_size_mib() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const HeapObject* a, const HeapObject* b) {
  return a->logical_buffer_size_mib() > b->logical_buffer_size_mib();
}

void test1(const HeapObject* a, const HeapObject* b, const HeapObject* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const HeapObject* a, const HeapObject* b, const HeapObject* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const HeapObject* a, const HeapObject* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const HeapObject* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}