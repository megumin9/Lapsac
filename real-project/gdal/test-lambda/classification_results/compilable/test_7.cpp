
#include <bits/stdc++.h>
using namespace std;

struct LayerStruct {
    int iPage;
    int nInsertIdx;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const LayerStruct &a, const LayerStruct &b) {
    if (a.iPage < b.iPage)
        return true;
    if (a.iPage > b.iPage)
        return false;
    return a.nInsertIdx < b.nInsertIdx;
}

void test1(LayerStruct a, LayerStruct b, LayerStruct c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(LayerStruct a, LayerStruct b, LayerStruct c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(LayerStruct a, LayerStruct b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(LayerStruct a, LayerStruct b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(LayerStruct a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}
