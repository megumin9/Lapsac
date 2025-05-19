#include <bits/stdc++.h>

extern std::string GROUP_BASE;
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(std::string& a, std::string& b) {
    if (a == GROUP_BASE) {
        return false;
    }
    else if (b == GROUP_BASE) {
        return true;
    }
    else {
        return a < b;
    }
}

void test1(std::string& a, std::string& b, std::string& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(std::string& a, std::string& b, std::string& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(std::string& a, std::string& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(std::string& a, std::string& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(std::string& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}