#include <bits/stdc++.h>
using namespace std;

struct Strip {
    int machine;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Strip *a, const Strip *b) {
    return a->machine < b->machine;
}

void test1(Strip* a, Strip* b, Strip* c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(Strip* a, Strip* b, Strip* c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(Strip* a, Strip* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(Strip* a, Strip* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(Strip* a){
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}