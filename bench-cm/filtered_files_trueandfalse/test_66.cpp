#include <bits/stdc++.h>
using namespace std;

struct Candidate {
    int calls;
    int node;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_9(const Candidate& left, const Candidate& right) {
  if (left.calls != right.calls) {
    return left.calls > right.calls;
  }
  return left.node < right.node;
}

void test1(const Candidate& a, const Candidate& b, const Candidate& c) {
  NewTest();
  if (!compare_9(a,b) && !compare_9(b,c) && compare_9(a,c)) 
    ConsistencyChecker();
}

void test2(const Candidate& a, const Candidate& b, const Candidate& c) {
  NewTest();
  if (compare_9(a,b) && compare_9(b,c) && compare_9(c,a)) 
    TransiveChecker();
}

void test3_1(const Candidate& a, const Candidate& b) {
  NewTest();
  if (compare_9(a,b) && compare_9(b,a))
    SymmetryChecker();
}

void test3_2(const Candidate& a, const Candidate& b) {
  NewTest();
  if (compare_9(a,b) && compare_9(b,a))
    SymmetryChecker();
}

void test4(const Candidate& a) {
  NewTest();
  if (compare_9(a, a)) 
    ReflexivityChecker();
}