
#include <bits/stdc++.h>
struct PrimitiveData {
    int z;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const PrimitiveData & a, const PrimitiveData & b) {
    return a.z < b.z;
}

void test1(PrimitiveData a, PrimitiveData b, PrimitiveData c){
    NewTest();
    if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(PrimitiveData a, PrimitiveData b, PrimitiveData c){
    NewTest();
    if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(PrimitiveData a, PrimitiveData b){
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(PrimitiveData a){
    NewTest();
    if (lambda2(a, a))
    ReflexivityChecker();
}
