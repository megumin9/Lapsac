#include <bits/stdc++.h>
using namespace std;

class FeaturePart {
public:
    int length() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(FeaturePart * a, FeaturePart * b) {
    return a->length() > b->length();
}

void test1(FeaturePart* a, FeaturePart* b, FeaturePart* c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(FeaturePart* a, FeaturePart* b, FeaturePart* c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(FeaturePart* a, FeaturePart* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(FeaturePart* a, FeaturePart* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(FeaturePart* a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}