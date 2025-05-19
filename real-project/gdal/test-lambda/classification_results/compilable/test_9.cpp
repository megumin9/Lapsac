#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<double, double> &oPair1,
             const std::pair<double, double> &oPair2) {
    return oPair1.first < oPair2.first;
}

void test1(const std::pair<double, double> &a, const std::pair<double, double> &b, const std::pair<double, double> &c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const std::pair<double, double> &a, const std::pair<double, double> &b, const std::pair<double, double> &c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const std::pair<double, double> &a, const std::pair<double, double> &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const std::pair<double, double> &a, const std::pair<double, double> &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const std::pair<double, double> &a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}