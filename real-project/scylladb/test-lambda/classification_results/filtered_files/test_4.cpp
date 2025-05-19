#include <bits/stdc++.h>

struct table_pair {
    int first;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const table_pair& a, const table_pair& b) {
    return a.first < b.first;
}

void test1(table_pair a, table_pair b, table_pair c){
    NewTest();
    if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(table_pair a, table_pair b, table_pair c){
    NewTest();
    if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(table_pair a, table_pair b){
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test3_2(table_pair a, table_pair b){
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(table_pair a){
    NewTest();
    if (lambda2(a, a))
    ReflexivityChecker();
}