#include <bits/stdc++.h>
#include <cstdint>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

std::vector<int64_t> ranks;

bool lambda0(int64_t i1, int64_t i2) {
    return ranks[i1] < ranks[i2];
}

void test1(int64_t a, int64_t b, int64_t c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(int64_t a, int64_t b, int64_t c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(int64_t a, int64_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(int64_t a, int64_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(int64_t a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}