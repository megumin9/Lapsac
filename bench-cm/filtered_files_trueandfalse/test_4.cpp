#include <bits/stdc++.h>

class CModEntry {
public:
    static bool compareVersions(const std::string&, const std::string&);
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_7(const std::string& lesser, const std::string& greater) {
    return !CModEntry::compareVersions(lesser, greater);
}

void test1(const std::string& a, const std::string& b, const std::string& c){
    NewTest();
    if (!compare_7(a,b) && !compare_7(b,c) && compare_7(a,c)) 
        ConsistencyChecker();
}

void test2(const std::string& a, const std::string& b, const std::string& c){
    NewTest();
    if (compare_7(a,b) && compare_7(b,c) && compare_7(c,a)) 
        TransiveChecker();
}

void test3_1(const std::string& a, const std::string& b){
    NewTest();
    if (compare_7(a,b) && compare_7(b,a)) 
        SymmetryChecker();
}

void test3_2(const std::string& a, const std::string& b){
    NewTest();
    if (compare_7(a,b) && compare_7(b,a)) 
        SymmetryChecker();
}

void test4(const std::string& a){
    NewTest();
    if (compare_7(a, a)) 
        ReflexivityChecker();
}