#include <bits/stdc++.h>

struct sortableYoloBBox {
    int** probs;
    int index;
    int cclass;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const sortableYoloBBox& a, const sortableYoloBBox& b) {
    int diff = a.probs[a.index][b.cclass] - b.probs[b.index][b.cclass];
    return diff > 0;
}

void test1(sortableYoloBBox a, sortableYoloBBox b, sortableYoloBBox c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(sortableYoloBBox a, sortableYoloBBox b, sortableYoloBBox c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(sortableYoloBBox a, sortableYoloBBox b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(sortableYoloBBox a, sortableYoloBBox b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(sortableYoloBBox a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}