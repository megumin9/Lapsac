#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

vector<int> quasi_static_tensors_producers;

bool lambda0(int t1, int t2) {
  return quasi_static_tensors_producers[t1] < quasi_static_tensors_producers[t2];
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

void test3_2(int a, int b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(int a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}