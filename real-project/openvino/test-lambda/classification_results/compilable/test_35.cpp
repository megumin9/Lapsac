#include <bits/stdc++.h>
using namespace std;

vector<size_t> strides;
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(size_t ind_l, size_t ind_r) {
    return (strides[ind_l] > strides[ind_r]);
}

void test1(size_t a, size_t b, size_t c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(size_t a, size_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(size_t a, size_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(size_t a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}