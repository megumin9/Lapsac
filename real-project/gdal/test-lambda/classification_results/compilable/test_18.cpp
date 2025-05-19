#include <bits/stdc++.h>

struct NodeItem {};

extern uint32_t HILBERT_MAX;
extern int minX, minY, width, height;

uint32_t hilbert(const NodeItem&, uint32_t, int, int, int, int);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const NodeItem &a, const NodeItem &b) {
    uint32_t ha = hilbert(a, HILBERT_MAX, minX, minY, width, height);
    uint32_t hb = hilbert(b, HILBERT_MAX, minX, minY, width, height);
    return ha > hb;
}

void test1(NodeItem a, NodeItem b, NodeItem c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(NodeItem a, NodeItem b, NodeItem c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(NodeItem a, NodeItem b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(NodeItem a, NodeItem b){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,a))
    SymmetryChecker();
}

void test4(NodeItem a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}