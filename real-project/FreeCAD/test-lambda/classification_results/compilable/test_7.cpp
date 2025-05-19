#include <bits/stdc++.h>

struct Base {
    struct Type {
        const char* getName() const;
    };
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(Base::Type a, Base::Type b) {
    return strcmp(a.getName(), b.getName()) < 0;
}

void test1(Base::Type a, Base::Type b, Base::Type c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
        ConsistencyChecker();
}

void test2(Base::Type a, Base::Type b, Base::Type c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(Base::Type a, Base::Type b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(Base::Type a, Base::Type b){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,a))
        SymmetryChecker();
}

void test4(Base::Type a){
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}