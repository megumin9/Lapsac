#include <bits/stdc++.h>
using namespace std;

struct Detection {
    int score;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Detection& a, const Detection& b) {
  return a.score > b.score;
}

void test1(Detection a, Detection b, Detection c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(Detection a, Detection b, Detection c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(Detection a, Detection b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(Detection a, Detection b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(Detection a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}