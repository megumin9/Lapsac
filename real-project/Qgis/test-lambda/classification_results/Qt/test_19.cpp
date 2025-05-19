#include <QtCore/QPair>

struct QgsPoint {};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QPair<double, QgsPoint>& a, const QPair<double, QgsPoint>& b) {
    return a.first < b.first;
}

void test1(const QPair<double, QgsPoint>& a, const QPair<double, QgsPoint>& b, const QPair<double, QgsPoint>& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QPair<double, QgsPoint>& a, const QPair<double, QgsPoint>& b, const QPair<double, QgsPoint>& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QPair<double, QgsPoint>& a, const QPair<double, QgsPoint>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QPair<double, QgsPoint>& a, const QPair<double, QgsPoint>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QPair<double, QgsPoint>& a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}