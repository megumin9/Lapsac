#include <bits/stdc++.h>
using namespace std;

struct KVT {
    int key;
    int idx;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(const KVT& lhs, const KVT& rhs) {
  return lhs.key == rhs.key ? lhs.idx < rhs.idx : lhs.key > rhs.key;
}

void test1(KVT a, KVT b, KVT c) {
  NewTest();
  if (!cmp(a, b) && !cmp(b, c) && cmp(a, c))
    ConsistencyChecker();
}

void test2(KVT a, KVT b, KVT c) {
  NewTest();
  if (cmp(a, b) && cmp(b, c) && cmp(c, a))
    TransiveChecker();
}

void test3_1(KVT a, KVT b) {
  NewTest();
  if (cmp(a, b) && cmp(b, a))
    SymmetryChecker();
}

void test3_2(KVT a, KVT b) {
  NewTest();
  if (cmp(a, b) && cmp(b, a))
    SymmetryChecker();
}

void test4(KVT a) {
  NewTest();
  if (cmp(a, a))
    ReflexivityChecker();
}