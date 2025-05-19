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

bool lambda2(const QgsLabelPosition &a, const QgsLabelPosition &b) {
    return a.labelText.compare( b.labelText ) < 0;
}

void test1(const QgsLabelPosition &a, const QgsLabelPosition &b, const QgsLabelPosition &c){
    NewTest();
    if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(const QgsLabelPosition &a, const QgsLabelPosition &b, const QgsLabelPosition &c){
    NewTest();
    if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(const QgsLabelPosition &a, const QgsLabelPosition &b){
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(const QgsLabelPosition &a){
    NewTest();
    if (lambda2(a, a))
    ReflexivityChecker();
}