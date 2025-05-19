#include <bits/stdc++.h>
using namespace std;

struct BufferAllocation {
    int size() const;
    int index() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const BufferAllocation& a, const BufferAllocation& b) {
  if (a.size() > b.size()) return true;
  if (a.size() < b.size()) return false;
  return a.index() < b.index();
}

void test1(const BufferAllocation& a, const BufferAllocation& b, const BufferAllocation& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const BufferAllocation& a, const BufferAllocation& b, const BufferAllocation& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const BufferAllocation& a, const BufferAllocation& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const BufferAllocation& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}