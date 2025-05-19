#include <bits/stdc++.h>

namespace ov {
struct NodeVector {
    size_t size() const;
};
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ov::NodeVector& a, const ov::NodeVector& b) {
    return a.size() > b.size();
}

void test1(const ov::NodeVector& a, const ov::NodeVector& b, const ov::NodeVector& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const ov::NodeVector& a, const ov::NodeVector& b, const ov::NodeVector& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const ov::NodeVector& a, const ov::NodeVector& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const ov::NodeVector& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}