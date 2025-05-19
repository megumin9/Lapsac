#include <bits/stdc++.h>
#include <QtCore/QModelIndex>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QModelIndex &a, const QModelIndex &b) {
    return b < a;
}

void test1(const QModelIndex &a, const QModelIndex &b, const QModelIndex &c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QModelIndex &a, const QModelIndex &b, const QModelIndex &c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QModelIndex &a, const QModelIndex &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QModelIndex &a, const QModelIndex &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QModelIndex &a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}