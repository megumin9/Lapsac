
#include <bits/stdc++.h>
using namespace std;

struct TensorEventDetail {
    int linearize_delinearize_time_ps() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const TensorEventDetail* a, const TensorEventDetail* b) {
  return a->linearize_delinearize_time_ps() < b->linearize_delinearize_time_ps();
}

void test1(const TensorEventDetail* a, const TensorEventDetail* b, const TensorEventDetail* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const TensorEventDetail* a, const TensorEventDetail* b, const TensorEventDetail* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const TensorEventDetail* a, const TensorEventDetail* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const TensorEventDetail* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}
