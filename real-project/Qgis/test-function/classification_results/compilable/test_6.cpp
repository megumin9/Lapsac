
#include <bits/stdc++.h>
struct QgsRendererRange;
bool valueLessThan(const QgsRendererRange &r1, const QgsRendererRange &r2);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool valueGreaterThan(const QgsRendererRange &r1, const QgsRendererRange &r2) {
    return !valueLessThan(r1, r2);
}

void test1(const QgsRendererRange &a, const QgsRendererRange &b, const QgsRendererRange &c) {
    NewTest();
    if (!valueGreaterThan(a, b) && !valueGreaterThan(b, c) && valueGreaterThan(a, c))
        ConsistencyChecker();
}

void test2(const QgsRendererRange &a, const QgsRendererRange &b, const QgsRendererRange &c) {
    NewTest();
    if (valueGreaterThan(a, b) && valueGreaterThan(b, c) && valueGreaterThan(c, a))
        TransiveChecker();
}

void test3_1(const QgsRendererRange &a, const QgsRendererRange &b) {
    NewTest();
    if (valueGreaterThan(a, b) && valueGreaterThan(b, a))
        SymmetryChecker();
}

void test3_2(const QgsRendererRange &a, const QgsRendererRange &b) {
    NewTest();
    if (valueGreaterThan(a, b) && valueGreaterThan(b, a))
        SymmetryChecker();
}

void test4(const QgsRendererRange &a) {
    NewTest();
    if (valueGreaterThan(a, a))
        ReflexivityChecker();
}
