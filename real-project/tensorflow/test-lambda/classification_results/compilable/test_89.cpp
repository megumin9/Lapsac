#include <bits/stdc++.h>
using namespace std;

struct Node {
    int32_t rank;
} nodes[1000];

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(int32_t a, int32_t b) {
    return nodes[a].rank < nodes[b].rank;
}

void test1(int32_t a, int32_t b, int32_t c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(int32_t a, int32_t b, int32_t c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(int32_t a, int32_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(int32_t a, int32_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(int32_t a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}