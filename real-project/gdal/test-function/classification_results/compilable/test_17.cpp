#include <bits/stdc++.h>
using namespace std;

struct SBNNodeIdBinStartPair {
    int nBinStart;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int SBNCompareNodeIdBinStartPairs(const void *a, const void *b) {
    return ((const SBNNodeIdBinStartPair *)a)->nBinStart -
           ((const SBNNodeIdBinStartPair *)b)->nBinStart;
}

void test1(const void *a, const void *b, const void *c){
    NewTest();
    if (!(SBNCompareNodeIdBinStartPairs(a,b)<0) && 
        !(SBNCompareNodeIdBinStartPairs(b,c)<0) && 
        (SBNCompareNodeIdBinStartPairs(a,c)<0))
    ConsistencyChecker();
}

void test2(const void *a, const void *b, const void *c){
    NewTest();
    if ((SBNCompareNodeIdBinStartPairs(a,b)<0) && 
        (SBNCompareNodeIdBinStartPairs(b,c)<0) && 
        (SBNCompareNodeIdBinStartPairs(c,a)<0))
    TransiveChecker();
}

void test3_1(const void *a, const void *b){
    NewTest();
    if ((SBNCompareNodeIdBinStartPairs(a,b)>0)&&
        (SBNCompareNodeIdBinStartPairs(b,a)>0))
    SymmetryChecker();
}

void test3_2(const void *a, const void *b){
    NewTest();
    if ((SBNCompareNodeIdBinStartPairs(a,b)<0)&&
        (SBNCompareNodeIdBinStartPairs(b,a)<0))
    SymmetryChecker();
}

void test4(const void *a){
    NewTest();
    if (SBNCompareNodeIdBinStartPairs(a,a)<0||SBNCompareNodeIdBinStartPairs(a,a)>0)
    ReflexivityChecker();
}