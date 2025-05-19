#include <bits/stdc++.h>

class Group {
public:
    using GPtr = std::shared_ptr<Group>;
    int getId() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const Group::GPtr& gptr_a, const Group::GPtr& gptr_b) {
    return gptr_a->getId() > gptr_b->getId();
}

void test1(Group::GPtr a, Group::GPtr b, Group::GPtr c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c)) 
        ConsistencyChecker();
}

void test2(Group::GPtr a, Group::GPtr b, Group::GPtr c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a)) 
        TransiveChecker();
}

void test3_1(Group::GPtr a, Group::GPtr b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(Group::GPtr a, Group::GPtr b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(Group::GPtr a){
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}