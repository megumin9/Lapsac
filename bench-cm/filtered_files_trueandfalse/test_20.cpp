#include <bits/stdc++.h>
using namespace std;

struct ComputeProgramKey {
    int shader;
    int layout;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_26(const ComputeProgramKey &a, const ComputeProgramKey &b) {
    return (a.shader < b.shader) || (a.layout < b.layout);
}

void test1(ComputeProgramKey a, ComputeProgramKey b, ComputeProgramKey c){
    NewTest();
    if (!compare_26(a,b) && !compare_26(b,c) && compare_26(a,c)) 
        ConsistencyChecker();
}

void test2(ComputeProgramKey a, ComputeProgramKey b, ComputeProgramKey c){
    NewTest();
    if (compare_26(a,b) && compare_26(b,c) && compare_26(c,a)) 
        TransiveChecker();
}

void test3_1(ComputeProgramKey a, ComputeProgramKey b){
    NewTest();
    if (compare_26(a,b) && compare_26(b,a))
        SymmetryChecker();
}

void test3_2(ComputeProgramKey a, ComputeProgramKey b){
    NewTest();
    if (compare_26(a,b) && compare_26(b,a))
        SymmetryChecker();
}

void test4(ComputeProgramKey a){
    NewTest();
    if (compare_26(a, a))
        ReflexivityChecker();
}