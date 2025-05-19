#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<std::string, size_t>& v1, const std::pair<std::string, size_t>& v2) {
    return v1.second < v2.second;
}

void test1(const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b, const std::pair<std::string, size_t>& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b, const std::pair<std::string, size_t>& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const std::pair<std::string, size_t>& a, const std::pair<std::string, size_t>& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const std::pair<std::string, size_t>& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}