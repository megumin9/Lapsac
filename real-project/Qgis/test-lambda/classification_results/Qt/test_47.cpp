#include <bits/stdc++.h>
#include <QtCore/QString>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda4(const QString &a, const QString &b) {
    return a.compare( b, Qt::CaseInsensitive ) < 0;
}

void test1(QString a, QString b, QString c){
    NewTest();
    if (!lambda4(a,b) && !lambda4(b,c) && lambda4(a,c))
    ConsistencyChecker();
}

void test2(QString a, QString b, QString c){
    NewTest();
    if (lambda4(a,b) && lambda4(b,c) && lambda4(c,a))
    TransiveChecker();
}

void test3_1(QString a, QString b){
    NewTest();
    if (lambda4(a,b) && lambda4(b,a))
    SymmetryChecker();
}

void test3_2(QString a, QString b){
    NewTest();
    if (lambda4(a,b) && lambda4(b,a))
    SymmetryChecker();
}

void test4(QString a){
    NewTest();
    if (lambda4(a, a))
    ReflexivityChecker();
}