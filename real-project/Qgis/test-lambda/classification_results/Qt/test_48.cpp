#include <bits/stdc++.h>
#include <QtCore/QVariant>
#include <QtCore/QString>
#include <QtCore/QMap>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QVariant &a, const QVariant &b) {
    return a.toMap().value( QStringLiteral( "resolution" ) ).toDouble() > b.toMap().value( QStringLiteral( "resolution" ) ).toDouble();
}

void test1(QVariant a, QVariant b, QVariant c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(QVariant a, QVariant b, QVariant c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(QVariant a, QVariant b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(QVariant a, QVariant b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(QVariant a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}