#include <bits/stdc++.h>
using namespace std;

struct GradComponent {
    int index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const GradComponent& x1, const GradComponent& x2) {
  return x1.index < x2.index;
}

void test1(GradComponent a, GradComponent b, GradComponent c){
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(GradComponent a, GradComponent b, GradComponent c){
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(GradComponent a, GradComponent b){
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(GradComponent a){
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}