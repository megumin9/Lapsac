
#include <bits/stdc++.h>
using namespace std;

class QgsRendererRange {
public:
    bool operator<(const QgsRendererRange&) const { return false; }
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool valueLessThan(const QgsRendererRange &r1, const QgsRendererRange &r2) {
    return r1 < r2;
}

void test1(const QgsRendererRange &a, const QgsRendererRange &b, const QgsRendererRange &c) {
    NewTest();
    if (!valueLessThan(a,b) && !valueLessThan(b,c) && valueLessThan(a,c))
        ConsistencyChecker();
}

void test2(const QgsRendererRange &a, const QgsRendererRange &b, const QgsRendererRange &c) {
    NewTest();
    if (valueLessThan(a,b) && valueLessThan(b,c) && valueLessThan(c,a))
        TransiveChecker();
}

void test3_1(const QgsRendererRange &a, const QgsRendererRange &b) {
    NewTest();
    if (valueLessThan(a,b) && valueLessThan(b,a))
        SymmetryChecker();
}

void test3_2(const QgsRendererRange &a, const QgsRendererRange &b) {
    NewTest();
    if (valueLessThan(a,b) && valueLessThan(b,a))
        SymmetryChecker();
}

void test4(const QgsRendererRange &a) {
    NewTest();
    if (valueLessThan(a,a))
        ReflexivityChecker();
}
