#include <bits/stdc++.h>
using namespace std;

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

void test1(QgsLayoutTableColumn a, QgsLayoutTableColumn b, QgsLayoutTableColumn c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(QgsLayoutTableColumn a, QgsLayoutTableColumn b, QgsLayoutTableColumn c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(QgsLayoutTableColumn a, QgsLayoutTableColumn b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(QgsLayoutTableColumn a, QgsLayoutTableColumn b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(QgsLayoutTableColumn a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}