
#include <bits/stdc++.h>

struct SizeClass {
    int size;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const SizeClass &a, const SizeClass &b) {
    return a.size > b.size;
}

void test1(const SizeClass &a, const SizeClass &b, const SizeClass &c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const SizeClass &a, const SizeClass &b, const SizeClass &c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const SizeClass &a, const SizeClass &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const SizeClass &a, const SizeClass &b){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,a))
    SymmetryChecker();
}

void test4(const SizeClass &a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}
