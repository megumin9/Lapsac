#include <bits/stdc++.h>

namespace Base {
    struct Type {
        const char* getName() const;
    };
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(Base::Type a, Base::Type b) {
    return strcmp(a.getName(), b.getName()) < 0;
}

void test1(Base::Type a, Base::Type b, Base::Type c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(Base::Type a, Base::Type b, Base::Type c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(Base::Type a, Base::Type b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(Base::Type a, Base::Type b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(Base::Type a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}