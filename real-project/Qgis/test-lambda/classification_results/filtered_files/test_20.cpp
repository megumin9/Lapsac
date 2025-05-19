#include <bits/stdc++.h>

class QgsCurve {
public:
    int compareTo(const QgsCurve* other) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsCurve *a, const QgsCurve *b) {
    return a->compareTo( b ) > 0;
}

void test1(const QgsCurve *a, const QgsCurve *b, const QgsCurve *c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const QgsCurve *a, const QgsCurve *b, const QgsCurve *c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const QgsCurve *a, const QgsCurve *b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) 
        SymmetryChecker();
}

void test3_2(const QgsCurve *a, const QgsCurve *b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) 
        SymmetryChecker();
}

void test4(const QgsCurve *a) {
    NewTest();
    if (lambda0(a, a)) 
        ReflexivityChecker();
}