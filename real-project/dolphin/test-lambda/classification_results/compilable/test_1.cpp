#include <bits/stdc++.h>

struct Test {
    std::string name;
};

using hashedTest = std::pair<size_t, Test*>;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(hashedTest const& lhs, hashedTest const& rhs) {
    if (lhs.first == rhs.first) {
        return lhs.second->name < rhs.second->name;
    }
    return lhs.first < rhs.first;
}

void test1(hashedTest const& a, hashedTest const& b, hashedTest const& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(hashedTest const& a, hashedTest const& b, hashedTest const& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(hashedTest const& a, hashedTest const& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(hashedTest const& a, hashedTest const& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(hashedTest const& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}