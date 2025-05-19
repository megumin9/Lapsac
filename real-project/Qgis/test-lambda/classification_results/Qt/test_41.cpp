#include <bits/stdc++.h>
#include <QtWidgets/QAction>
#include <QString>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(QAction *a, QAction *b) {
    return QString::localeAwareCompare( a->text(), b->text() ) < 0;
}

void test1(QAction *a, QAction *b, QAction *c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(QAction *a, QAction *b, QAction *c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(QAction *a, QAction *b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(QAction *a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}