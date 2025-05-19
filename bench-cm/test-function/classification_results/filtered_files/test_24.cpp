#include <bits/stdc++.h>

struct Candidate {
    int node;
    int calls;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_9(const Candidate& left, const Candidate& right) {
    return left.node != right.node && left.calls >= right.calls;
}

void test1(Candidate a, Candidate b, Candidate c) {
    NewTest();
    if (!compare_9(a, b) && !compare_9(b, c) && compare_9(a, c))
    ConsistencyChecker();
}

void test2(Candidate a, Candidate b, Candidate c) {
    NewTest();
    if (compare_9(a, b) && compare_9(b, c) && compare_9(c, a))
    TransiveChecker();
}

void test3_1(Candidate a, Candidate b) {
    NewTest();
    if (compare_9(a, b) && compare_9(b, a))
    SymmetryChecker();
}

void test3_2(Candidate a, Candidate b) {
    NewTest();
    if (compare_9(a, b) && compare_9(b, a))
    SymmetryChecker();
}

void test4(Candidate a) {
    NewTest();
    if (compare_9(a, a))
    ReflexivityChecker();
}