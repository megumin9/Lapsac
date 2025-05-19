#include <bits/stdc++.h>

struct ValueOIDPair {
    int first;
    int second;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ValueOIDPair &a, const ValueOIDPair &b) {
    return a.first < b.first ||
           (a.first == b.first && a.second < b.second);
}

void test1(const ValueOIDPair &a, const ValueOIDPair &b, const ValueOIDPair &c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
        ConsistencyChecker();
    }
}

void test2(const ValueOIDPair &a, const ValueOIDPair &b, const ValueOIDPair &c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
        TransiveChecker();
    }
}

void test3_1(const ValueOIDPair &a, const ValueOIDPair &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(const ValueOIDPair &a, const ValueOIDPair &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test4(const ValueOIDPair &a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}