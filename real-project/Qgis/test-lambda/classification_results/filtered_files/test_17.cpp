
#include <bits/stdc++.h>

class QgsAbstractGeometry {
public:
    int compareTo(const QgsAbstractGeometry* other) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsAbstractGeometry * a, const QgsAbstractGeometry * b) {
    return a->compareTo( b ) > 0;
}

void test1(const QgsAbstractGeometry * a, const QgsAbstractGeometry * b, const QgsAbstractGeometry * c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const QgsAbstractGeometry * a, const QgsAbstractGeometry * b, const QgsAbstractGeometry * c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const QgsAbstractGeometry * a, const QgsAbstractGeometry * b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const QgsAbstractGeometry * a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}
