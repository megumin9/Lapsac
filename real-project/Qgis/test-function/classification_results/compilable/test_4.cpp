#include <bits/stdc++.h>
using namespace std;

struct QgsGradientStop {
    int offset;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool stopLessThan(const QgsGradientStop &s1, const QgsGradientStop &s2)
{
    return s1.offset < s2.offset;
}

void test1(const QgsGradientStop &a, const QgsGradientStop &b, const QgsGradientStop &c){
    NewTest();
    if (!stopLessThan(a,b) && !stopLessThan(b,c) && stopLessThan(a,c))
        ConsistencyChecker();
}

void test2(const QgsGradientStop &a, const QgsGradientStop &b, const QgsGradientStop &c){
    NewTest();
    if (stopLessThan(a,b) && stopLessThan(b,c) && stopLessThan(c,a))
        TransiveChecker();
}

void test3_1(const QgsGradientStop &a, const QgsGradientStop &b){
    NewTest();
    if (stopLessThan(a,b) && stopLessThan(b,a))
        SymmetryChecker();
}

void test3_2(const QgsGradientStop &a, const QgsGradientStop &b){
    NewTest();
    if (stopLessThan(a,b) && stopLessThan(b,a))
        SymmetryChecker();
}

void test4(const QgsGradientStop &a){
    NewTest();
    if (stopLessThan(a, a))
        ReflexivityChecker();
}