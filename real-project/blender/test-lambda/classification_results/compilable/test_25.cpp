#include <bits/stdc++.h>

struct bNode {
    unsigned int ui_order;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const bNode *a, const bNode *b) {
    return a->ui_order < b->ui_order;
}

void test1(const bNode *a, const bNode *b, const bNode *c) {
    NewTest();
    if (!lambda1(a, b) && !lambda1(b, c) && lambda1(a, c)) {
        ConsistencyChecker();
    }
}

void test2(const bNode *a, const bNode *b, const bNode *c) {
    NewTest();
    if (lambda1(a, b) && lambda1(b, c) && lambda1(c, a)) {
        TransiveChecker();
    }
}

void test3_1(const bNode *a, const bNode *b) {
    NewTest();
    if (lambda1(a, b) && lambda1(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(const bNode *a, const bNode *b) {
    NewTest();
    if (lambda1(a, b) && lambda1(b, a)) {
        SymmetryChecker();
    }
}

void test4(const bNode *a) {
    NewTest();
    if (lambda1(a, a)) {
        ReflexivityChecker();
    }
}