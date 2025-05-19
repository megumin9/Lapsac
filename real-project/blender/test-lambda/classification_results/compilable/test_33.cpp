#include <bits/stdc++.h>
struct CourseBoundary {
    int index;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const CourseBoundary &a, const CourseBoundary &b) {
    return a.index < b.index;
}

void test1(CourseBoundary &a, CourseBoundary &b, CourseBoundary &c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(CourseBoundary &a, CourseBoundary &b, CourseBoundary &c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(CourseBoundary &a, CourseBoundary &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(CourseBoundary &a, CourseBoundary &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(CourseBoundary &a) {
    NewTest();
    if (lambda0(a,a))
    ReflexivityChecker();
}