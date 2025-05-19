#include <bits/stdc++.h>

struct Group {
    struct G {
        int getId() const;
    };
    using GPtr = std::shared_ptr<G>;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda4(const Group::GPtr& gptr_a, const Group::GPtr& gptr_b) {
    return gptr_a->getId() > gptr_b->getId();
}

void test1(Group::GPtr a, Group::GPtr b, Group::GPtr c) {
    NewTest();
    if (!lambda4(a,b) && !lambda4(b,c) && lambda4(a,c)) 
        ConsistencyChecker();
}

void test2(Group::GPtr a, Group::GPtr b, Group::GPtr c) {
    NewTest();
    if (lambda4(a,b) && lambda4(b,c) && lambda4(c,a)) 
        TransiveChecker();
}

void test3_1(Group::GPtr a, Group::GPtr b) {
    NewTest();
    if (lambda4(a,b) && lambda4(b,a))
        SymmetryChecker();
}

void test3_2(Group::GPtr a, Group::GPtr b) {
    NewTest();
    if (lambda4(a,b) && lambda4(b,a))
        SymmetryChecker();
}

void test4(Group::GPtr a) {
    NewTest();
    if (lambda4(a, a))
        ReflexivityChecker();
}