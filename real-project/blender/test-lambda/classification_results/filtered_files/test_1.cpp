
#include <bits/stdc++.h>
using namespace std;

struct LightTreeEmitter {
    int light_set_membership;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const LightTreeEmitter &a, const LightTreeEmitter &b) {
    return a.light_set_membership < b.light_set_membership;
}

void test1(const LightTreeEmitter &a, const LightTreeEmitter &b, const LightTreeEmitter &c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
        ConsistencyChecker();
    }
}

void test2(const LightTreeEmitter &a, const LightTreeEmitter &b, const LightTreeEmitter &c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
        TransiveChecker();
    }
}

void test3_1(const LightTreeEmitter &a, const LightTreeEmitter &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(const LightTreeEmitter &a, const LightTreeEmitter &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test4(const LightTreeEmitter &a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}
