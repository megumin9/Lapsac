#include <bits/stdc++.h>

class Accidental {
public:
    int stackingOrder() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_1(const Accidental* acc1, const Accidental* acc2) {
    return acc1->stackingOrder() <= acc2->stackingOrder();
}

void test1(Accidental* a, Accidental* b, Accidental* c) {
    NewTest();
    if (!compare_1(a, b) && !compare_1(b, c) && compare_1(a, c))
        ConsistencyChecker();
}

void test2(Accidental* a, Accidental* b, Accidental* c) {
    NewTest();
    if (compare_1(a, b) && compare_1(b, c) && compare_1(c, a))
        TransiveChecker();
}

void test3_1(Accidental* a, Accidental* b) {
    NewTest();
    if (compare_1(a, b) && compare_1(b, a))
        SymmetryChecker();
}

void test3_2(Accidental* a, Accidental* b) {
    NewTest();
    if (compare_1(a, b) && compare_1(b, a))
        SymmetryChecker();
}

void test4(Accidental* a) {
    NewTest();
    if (compare_1(a, a))
        ReflexivityChecker();
}