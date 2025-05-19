#include <bits/stdc++.h>
#include <tuple>
#include <string_view>

struct Node {
    std::string_view name() const;
};

struct Edge {
    int src_output() const;
    const Node* src() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Edge* a, const Edge* b) {
    int a_src_output = a->src_output();
    int b_src_output = b->src_output();
    std::string_view a_name(a->src()->name());
    std::string_view b_name(b->src()->name());
    return std::tie(a_src_output, a_name) < std::tie(b_src_output, b_name);
}

void test1(const Edge* a, const Edge* b, const Edge* c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const Edge* a, const Edge* b, const Edge* c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const Edge* a, const Edge* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const Edge* a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}