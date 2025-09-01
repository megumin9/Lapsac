#include <bits/stdc++.h>
struct PatchPrimaryKey {
    int msb;
    int lsb;
    int program_number;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_23(const PatchPrimaryKey& a, const PatchPrimaryKey& b) {
    if (a.msb < b.msb) {
        return true;
    } else if (a.msb == b.msb && a.lsb < b.lsb) {
        return true;
    } else if (a.lsb == b.lsb && a.program_number < b.program_number) {
        return true;
    }
    return false;
}

void test1(const PatchPrimaryKey& a, const PatchPrimaryKey& b, const PatchPrimaryKey& c){
    NewTest();
    if (!compare_23(a,b) && !compare_23(b,c) && compare_23(a,c)) 
        ConsistencyChecker();
}

void test2(const PatchPrimaryKey& a, const PatchPrimaryKey& b, const PatchPrimaryKey& c){
    NewTest();
    if (compare_23(a,b) && compare_23(b,c) && compare_23(c,a)) 
        TransiveChecker();
}

void test3_1(const PatchPrimaryKey& a, const PatchPrimaryKey& b){
    NewTest();
    if (compare_23(a,b) && compare_23(b,a)) 
        SymmetryChecker();
}

void test3_2(const PatchPrimaryKey& a, const PatchPrimaryKey& b){
    NewTest();
    if (compare_23(a,b) && compare_23(b,a)) 
        SymmetryChecker();
}

void test4(const PatchPrimaryKey& a){
    NewTest();
    if (compare_23(a, a)) 
        ReflexivityChecker();
}