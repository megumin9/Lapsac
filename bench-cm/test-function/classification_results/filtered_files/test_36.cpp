
#include <bits/stdc++.h>

struct CGPathNode {
    int turns;
    int moveRemains;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_21(const CGPathNode * lhs, const CGPathNode * rhs) {
    if (rhs->turns > lhs->turns)
        return false;
    if (rhs->turns == lhs->turns && rhs->moveRemains < lhs->moveRemains)
        return false;
    return true;
}

void test1(const CGPathNode* a, const CGPathNode* b, const CGPathNode* c){
    NewTest();
    if (!compare_21(a,b) && !compare_21(b,c) && compare_21(a,c)) 
        ConsistencyChecker();
}

void test2(const CGPathNode* a, const CGPathNode* b, const CGPathNode* c){
    NewTest();
    if (compare_21(a,b) && compare_21(b,c) && compare_21(c,a)) 
        TransiveChecker();
}

void test3_1(const CGPathNode* a, const CGPathNode* b){
    NewTest();
    if (compare_21(a,b) && compare_21(b,a))
        SymmetryChecker();
}

void test3_2(const CGPathNode* a, const CGPathNode* b){
    NewTest();
    if (compare_21(a,b) && compare_21(b,a))
        SymmetryChecker();
}

void test4(const CGPathNode* a){
    NewTest();
    if (compare_21(a, a)) 
        ReflexivityChecker();
}
