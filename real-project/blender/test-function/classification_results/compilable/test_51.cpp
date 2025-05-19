#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

using Real = int;

bool compare(const Real x, const Real y) {
    return x > y;
}

void test1(Real a, Real b, Real c){
    NewTest();
    if (!compare(a,b) && !compare(b,c) && compare(a,c))
    ConsistencyChecker();
}

void test2(Real a, Real b, Real c){
    NewTest();
    if (compare(a,b) && compare(b,c) && compare(c,a))
    TransiveChecker();
}

void test3_1(Real a, Real b){
    NewTest();
    if (compare(a,b) && compare(b,a))
    SymmetryChecker();
}

void test3_2(Real a, Real b){
    NewTest();
    if (compare(a,b) && compare(b,a))
    SymmetryChecker();
}

void test4(Real a){
    NewTest();
    if (compare(a, a))
    ReflexivityChecker();
}