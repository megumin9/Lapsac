
#include <bits/stdc++.h>

class QgsDataItemGuiProvider {
public:
    int precedenceWhenPopulatingMenus() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(QgsDataItemGuiProvider *a, QgsDataItemGuiProvider *b) {
    return a->precedenceWhenPopulatingMenus() < b->precedenceWhenPopulatingMenus();
}

void test1(QgsDataItemGuiProvider* a, QgsDataItemGuiProvider* b, QgsDataItemGuiProvider* c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(QgsDataItemGuiProvider* a, QgsDataItemGuiProvider* b, QgsDataItemGuiProvider* c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(QgsDataItemGuiProvider* a, QgsDataItemGuiProvider* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(QgsDataItemGuiProvider* a, QgsDataItemGuiProvider* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(QgsDataItemGuiProvider* a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}
