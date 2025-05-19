#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::vector<size_t>& a, const std::vector<size_t>& b) {
    return a.size() > b.size();
}

void test1(std::vector<size_t> a, std::vector<size_t> b, std::vector<size_t> c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(std::vector<size_t> a, std::vector<size_t> b, std::vector<size_t> c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(std::vector<size_t> a, std::vector<size_t> b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(std::vector<size_t> a, std::vector<size_t> b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(std::vector<size_t> a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}