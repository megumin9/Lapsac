#include <bits/stdc++.h>
using namespace std;

extern vector<int> input_probs;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(size_t i1, size_t i2) {
    return input_probs[i1] > input_probs[i2];
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