#include <bits/stdc++.h>

struct repair_plan {
    int repair_time_diff;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const repair_plan& x, const repair_plan& y) {
    return x.repair_time_diff > y.repair_time_diff;
}

void test1(const repair_plan& a, const repair_plan& b, const repair_plan& c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
        ConsistencyChecker();
    }
}

void test2(const repair_plan& a, const repair_plan& b, const repair_plan& c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
        TransiveChecker();
    }
}

void test3_1(const repair_plan& a, const repair_plan& b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(const repair_plan& a, const repair_plan& b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test4(const repair_plan& a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}