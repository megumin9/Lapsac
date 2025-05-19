#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_19(const std::string& a, const std::string& b) {
    if (a == "COLD_START" && b != "COLD_START") {
        return true;
    }
    if (a == b) {
        return false;
    }
    return a < b;
}

void test1(const std::string& a, const std::string& b, const std::string& c){
    NewTest();
    if (!compare_19(a,b) && !compare_19(b,c) && compare_19(a,c)) 
        ConsistencyChecker();
}

void test2(const std::string& a, const std::string& b, const std::string& c){
    NewTest();
    if (compare_19(a,b) && compare_19(b,c) && compare_19(c,a)) 
        TransiveChecker();
}

void test3_1(const std::string& a, const std::string& b){
    NewTest();
    if (compare_19(a,b) && compare_19(b,a))
        SymmetryChecker();
}

void test3_2(const std::string& a, const std::string& b){
    NewTest();
    if (compare_19(a,b) && compare_19(b,a))
        SymmetryChecker();
}

void test4(const std::string& a){
    NewTest();
    if (compare_19(a, a)) 
        ReflexivityChecker();
}