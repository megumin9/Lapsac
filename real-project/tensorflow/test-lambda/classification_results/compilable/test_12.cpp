#include <bits/stdc++.h>
using namespace std;

vector<int> mutexes;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(int a, int b) {
  return mutexes[a] < mutexes[b];
}

void test1(int a, int b, int c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(int a, int b, int c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(int a, int b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(int a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}