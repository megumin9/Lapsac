#include <bits/stdc++.h>

struct QgsLayoutTableColumn {
    int sortByRank() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b) {
    return a.sortByRank() < b.sortByRank();
}

void test1(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b, const QgsLayoutTableColumn & c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b, const QgsLayoutTableColumn & c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QgsLayoutTableColumn & a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}