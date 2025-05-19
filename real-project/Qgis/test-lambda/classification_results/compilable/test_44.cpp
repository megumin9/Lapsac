#include <bits/stdc++.h>
#include <string>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const std::string &a, const std::string &b) {
    return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(),
        [](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); });
}

void test1(std::string a, std::string b, std::string c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(std::string a, std::string b, std::string c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(std::string a, std::string b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(std::string a, std::string b){}

void test4(std::string a){
    NewTest();
    if (lambda1(a,a))
    ReflexivityChecker();
}