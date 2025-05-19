#include <bits/stdc++.h>

namespace Qt3DCore {
    class QEntity {
    public:
        std::string objectName() const;
    };
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Qt3DCore::QEntity *a, const Qt3DCore::QEntity *b) {
    return a->objectName() < b->objectName();
}

void test1(const Qt3DCore::QEntity *a, const Qt3DCore::QEntity *b, const Qt3DCore::QEntity *c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
        ConsistencyChecker();
}

void test2(const Qt3DCore::QEntity *a, const Qt3DCore::QEntity *b, const Qt3DCore::QEntity *c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
        TransiveChecker();
}

void test3_1(const Qt3DCore::QEntity *a, const Qt3DCore::QEntity *b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test4(const Qt3DCore::QEntity *a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}