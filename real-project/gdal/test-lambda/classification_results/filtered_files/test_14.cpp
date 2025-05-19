#include <bits/stdc++.h>
struct GeometryNamesStruct {
    int nHash;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const GeometryNamesStruct &a, const GeometryNamesStruct &b) {
    return a.nHash < b.nHash;
}

void test1(GeometryNamesStruct a, GeometryNamesStruct b, GeometryNamesStruct c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(GeometryNamesStruct a, GeometryNamesStruct b, GeometryNamesStruct c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(GeometryNamesStruct a, GeometryNamesStruct b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(GeometryNamesStruct a, GeometryNamesStruct b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(GeometryNamesStruct a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}