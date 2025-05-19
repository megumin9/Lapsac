#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const std::pair<int, int>& first, const std::pair<int, int>& second) {
    return first.second > second.second;
}

void test1(const std::pair<int, int>& a, const std::pair<int, int>& b, const std::pair<int, int>& c) {
    NewTest();
    if (!lambda2(a, b) && !lambda2(b, c) && lambda2(a, c)) 
        ConsistencyChecker();
}

void test2(const std::pair<int, int>& a, const std::pair<int, int>& b, const std::pair<int, int>& c) {
    NewTest();
    if (lambda2(a, b) && lambda2(b, c) && lambda2(c, a)) 
        TransiveChecker();
}

void test3_1(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    NewTest();
    if (lambda2(a, b) && lambda2(b, a))
        SymmetryChecker();
}

void test3_2(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    NewTest();
    if (lambda2(a, b) && lambda2(b, a))
        SymmetryChecker();
}

void test4(const std::pair<int, int>& a) {
    NewTest();
    if (lambda2(a, a))
        ReflexivityChecker();
}