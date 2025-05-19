#include <bits/stdc++.h>
#include <string>

struct QgsLabelPosition {
    std::string labelText;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsLabelPosition &a, const QgsLabelPosition &b) {
    return a.labelText.compare( b.labelText ) < 0;
}

void test1(const QgsLabelPosition &a, const QgsLabelPosition &b, const QgsLabelPosition &c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QgsLabelPosition &a, const QgsLabelPosition &b, const QgsLabelPosition &c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QgsLabelPosition &a, const QgsLabelPosition &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QgsLabelPosition &a, const QgsLabelPosition &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QgsLabelPosition &a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}