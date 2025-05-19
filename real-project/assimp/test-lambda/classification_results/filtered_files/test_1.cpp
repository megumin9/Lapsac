#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Node* a, const Node* b) {
    return a->x < b->x;
}

void test1(const Node* a, const Node* b, const Node* c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(const Node* a, const Node* b, const Node* c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(const Node* a, const Node* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const Node* a, const Node* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const Node* a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}