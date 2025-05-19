#include <bits/stdc++.h>

struct QModelIndex {};

bool operator<(const QModelIndex&, const QModelIndex&);

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool operator<(const QModelIndex &a, const QModelIndex &b) { return false; }

bool lambda1(const QModelIndex &a, const QModelIndex &b) {
    return b < a;
}

void test1(QModelIndex a, QModelIndex b, QModelIndex c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(QModelIndex a, QModelIndex b, QModelIndex c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(QModelIndex a, QModelIndex b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(QModelIndex a, QModelIndex b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(QModelIndex a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}