#include <bits/stdc++.h>
#include <QtCore/QString>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda3(const QString &a, const QString &b) {
  return a.compare( b, Qt::CaseInsensitive ) < 0;
}

void test1(const QString &a, const QString &b, const QString &c){
NewTest();
if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c)) 
ConsistencyChecker();
}

void test2(const QString &a, const QString &b, const QString &c){
NewTest();
if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a)) 
TransiveChecker();
}

void test3_1(const QString &a, const QString &b){
NewTest();
if (lambda3(a,b) && lambda3(b,a))
SymmetryChecker();
}

void test3_2(const QString &a, const QString &b){
NewTest();
if (lambda3(a,b) && lambda3(b,a))
SymmetryChecker();
}

void test4(const QString &a){
NewTest();
if (lambda3(a, a))
ReflexivityChecker();
}