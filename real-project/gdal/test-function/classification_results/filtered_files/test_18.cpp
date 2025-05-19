#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_ints(const void *a, const void *b) {
    return *static_cast<const int*>(a) - *static_cast<const int*>(b);
}

void test1(void* a, void* b, void* c){
    NewTest();
    if (!(compare_ints(a,b)<0) && !(compare_ints(b,c)<0) && (compare_ints(a,c)<0))
        ConsistencyChecker();
}

void test2(void* a, void* b, void* c){
    NewTest();
    if ((compare_ints(a,b)<0) && (compare_ints(b,c)<0) && (compare_ints(c,a)<0))
        TransiveChecker();
}

void test3_1(void* a, void* b){
    NewTest();
    if ((compare_ints(a,b)>0)&&(compare_ints(b,a)>0))
        SymmetryChecker();
}

void test3_2(void* a, void* b){
    NewTest();
    if ((compare_ints(a,b)<0)&&(compare_ints(b,a)<0))
        SymmetryChecker();
}

void test4(void* a){
    NewTest();
    if (compare_ints(a,a)<0||compare_ints(a,a)>0)
        ReflexivityChecker();
}