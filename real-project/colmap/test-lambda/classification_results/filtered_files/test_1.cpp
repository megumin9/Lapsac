#include <bits/stdc++.h>
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<int, int> image1, const std::pair<int, int> image2) {
    return image1.second > image2.second;
}

void test1(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) 
        ConsistencyChecker();
}

void test2(std::pair<int, int> a, std::pair<int, int> b, std::pair<int, int> c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
        TransiveChecker();
}

void test3_1(std::pair<int, int> a, std::pair<int, int> b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test3_2(std::pair<int, int> a, std::pair<int, int> b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test4(std::pair<int, int> a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}