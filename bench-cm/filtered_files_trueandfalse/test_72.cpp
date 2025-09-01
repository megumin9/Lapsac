#include <bits/stdc++.h>
using namespace std;

struct Entry {
    int funcId;
    int count;
};

const int InvalidFuncId = 0;
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_11(const Entry& a, const Entry& b) {
  if (b.funcId == InvalidFuncId) return a.funcId != InvalidFuncId;
  if (a.funcId == InvalidFuncId) return false;
  return a.count > b.count;
}

void test1(const Entry& a, const Entry& b, const Entry& c) {
  NewTest();
  if (!compare_11(a,b) && !compare_11(b,c) && compare_11(a,c)) 
    ConsistencyChecker();
}

void test2(const Entry& a, const Entry& b, const Entry& c) {
  NewTest();
  if (compare_11(a,b) && compare_11(b,c) && compare_11(c,a)) 
    TransiveChecker();
}

void test3_1(const Entry& a, const Entry& b) {
  NewTest();
  if (compare_11(a,b) && compare_11(b,a))
    SymmetryChecker();
}

void test3_2(const Entry& a, const Entry& b) {
  NewTest();
  if (compare_11(a,b) && compare_11(b,a))
    SymmetryChecker();
}

void test4(const Entry& a) {
  NewTest();
  if (compare_11(a, a))
    ReflexivityChecker();
}