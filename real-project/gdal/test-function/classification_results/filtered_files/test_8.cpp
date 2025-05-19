#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool CompareStrings(const std::string &a, const std::string &b) {
    return a.compare(b) < 0;
}

void test1(std::string a, std::string b, std::string c) {
    NewTest();
    if (!CompareStrings(a,b) && !CompareStrings(b,c) && CompareStrings(a,c))
    ConsistencyChecker();
}

void test2(std::string a, std::string b, std::string c) {
    NewTest();
    if (CompareStrings(a,b) && CompareStrings(b,c) && CompareStrings(c,a))
    TransiveChecker();
}

void test3_1(std::string a, std::string b) {
    NewTest();
    if (CompareStrings(a,b) && CompareStrings(b,a))
    SymmetryChecker();
}

void test3_2(std::string a, std::string b) {
    NewTest();
    if (CompareStrings(a,b) && CompareStrings(b,a))
    SymmetryChecker();
}

void test4(std::string a) {
    NewTest();
    if (CompareStrings(a, a))
    ReflexivityChecker();
}