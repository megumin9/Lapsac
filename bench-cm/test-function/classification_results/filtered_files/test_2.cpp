#include <bits/stdc++.h>

int formatSortPriority(const std::string&);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_17(const std::string &lhs, const std::string &rhs) {
    return formatSortPriority(lhs) > formatSortPriority(rhs) || lhs < rhs;
}

void test1(std::string a, std::string b, std::string c){
    NewTest();
    if (!compare_17(a,b) && !compare_17(b,c) && compare_17(a,c))
    ConsistencyChecker();
}

void test2(std::string a, std::string b, std::string c){
    NewTest();
    if (compare_17(a,b) && compare_17(b,c) && compare_17(c,a))
    TransiveChecker();
}

void test3_1(std::string a, std::string b){
    NewTest();
    if (compare_17(a,b) && compare_17(b,a))
    SymmetryChecker();
}

void test3_2(std::string a, std::string b){
    NewTest();
    if (compare_17(a,b) && compare_17(b,a))
    SymmetryChecker();
}

void test4(std::string a){
    NewTest();
    if (compare_17(a, a))
    ReflexivityChecker();
}