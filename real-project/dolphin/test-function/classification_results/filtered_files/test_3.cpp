
#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int CompareItemsByValue(const void* lhs, const void* rhs) {
    const int* a = (const int*)lhs;
    const int* b = (const int*)rhs;
    return (*a - *b) > 0 ? +1 : -1;
}

void test1(int* a, int* b, int* c){
    NewTest();
    if (!(CompareItemsByValue(a,b)<0) && !(CompareItemsByValue(b,c)<0) && (CompareItemsByValue(a,c)<0))
        ConsistencyChecker();
}

void test2(int* a, int* b, int* c){
    NewTest();
    if ((CompareItemsByValue(a,b)<0) && (CompareItemsByValue(b,c)<0) && (CompareItemsByValue(c,a)<0))
        TransiveChecker();
}

void test3_1(int* a, int* b){
    NewTest();
    if ((CompareItemsByValue(a,b)>0)&&(CompareItemsByValue(b,a)>0))
        SymmetryChecker();
}

void test3_2(int* a, int* b){
    NewTest();
    if ((CompareItemsByValue(a,b)<0)&&(CompareItemsByValue(b,a)<0))
        SymmetryChecker();
}

void test4(int* a){
    NewTest();
    if (CompareItemsByValue(a, a)<0||CompareItemsByValue(a, a)>0)
        ReflexivityChecker();
}
