#include <bits/stdc++.h>
using namespace std;

class QgsLayoutTableColumn {
public:
    int sortByRank() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b) {
    return a.sortByRank() < b.sortByRank();
}

void test1(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b, const QgsLayoutTableColumn & c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b, const QgsLayoutTableColumn & c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(const QgsLayoutTableColumn & a, const QgsLayoutTableColumn & b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const QgsLayoutTableColumn & a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}