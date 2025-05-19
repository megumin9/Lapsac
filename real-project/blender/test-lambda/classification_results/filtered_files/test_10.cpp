#include <bits/stdc++.h>
using namespace std;

struct EdgeUUID {
    int edval;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const EdgeUUID &a, const EdgeUUID &b) {
    return a.edval < b.edval;
}

void test1(EdgeUUID a, EdgeUUID b, EdgeUUID c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) 
        ConsistencyChecker();
}

void test2(EdgeUUID a, EdgeUUID b, EdgeUUID c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) 
        TransiveChecker();
}

void test3_1(EdgeUUID a, EdgeUUID b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test4(EdgeUUID a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}