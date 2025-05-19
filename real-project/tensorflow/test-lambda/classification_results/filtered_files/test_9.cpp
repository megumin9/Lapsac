#include <bits/stdc++.h>
using namespace std;

struct LatencyBreakdown {
    int total_latency_us;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const LatencyBreakdown& a, const LatencyBreakdown& b) {
  return a.total_latency_us < b.total_latency_us;
}

void test1(const LatencyBreakdown& a, const LatencyBreakdown& b, const LatencyBreakdown& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(const LatencyBreakdown& a, const LatencyBreakdown& b, const LatencyBreakdown& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const LatencyBreakdown& a, const LatencyBreakdown& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const LatencyBreakdown& a, const LatencyBreakdown& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const LatencyBreakdown& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}