#include <bits/stdc++.h>
using namespace std;

struct AnchorAlongSegment {
    int along;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(AnchorAlongSegment p1, AnchorAlongSegment p2) {
    return p1.along < p2.along;
}

void test1(AnchorAlongSegment a, AnchorAlongSegment b, AnchorAlongSegment c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
        ConsistencyChecker();
}

void test2(AnchorAlongSegment a, AnchorAlongSegment b, AnchorAlongSegment c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
        TransiveChecker();
}

void test3_1(AnchorAlongSegment a, AnchorAlongSegment b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test3_2(AnchorAlongSegment a, AnchorAlongSegment b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test4(AnchorAlongSegment a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}