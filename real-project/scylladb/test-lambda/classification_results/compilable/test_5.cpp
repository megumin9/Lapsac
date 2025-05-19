#include <bits/stdc++.h>

struct table_pair {
    int first;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda3(const table_pair& a, const table_pair& b) {
    return a.first < b.first;
}

void test1(const table_pair& a, const table_pair& b, const table_pair& c) {
    NewTest();
    if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c))
        ConsistencyChecker();
}

void test2(const table_pair& a, const table_pair& b, const table_pair& c) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a))
        TransiveChecker();
}

void test3_1(const table_pair& a, const table_pair& b) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,a))
        SymmetryChecker();
}

void test3_2(const table_pair& a, const table_pair& b) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,a))
        SymmetryChecker();
}

void test4(const table_pair& a) {
    NewTest();
    if (lambda3(a, a))
        ReflexivityChecker();
}