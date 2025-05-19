#include <bits/stdc++.h>
using namespace std;

struct PrimitiveData {
    int z;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const PrimitiveData & a, const PrimitiveData & b) {
    return a.z < b.z;
}

void test1(PrimitiveData a, PrimitiveData b, PrimitiveData c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(PrimitiveData a, PrimitiveData b, PrimitiveData c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(PrimitiveData a, PrimitiveData b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(PrimitiveData a, PrimitiveData b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(PrimitiveData a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}