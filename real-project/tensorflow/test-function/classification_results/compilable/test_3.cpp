
#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int Compare(const void* a, const void* b) {
    return *reinterpret_cast<const int*>(a) - *reinterpret_cast<const int*>(b);
}

void test1(const void* a, const void* b, const void* c){
    NewTest();
    if (!(Compare(a,b)<0) && !(Compare(b,c)<0) && (Compare(a,c)<0))
        ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
    NewTest();
    if ((Compare(a,b)<0) && (Compare(b,c)<0) && (Compare(c,a)<0))
        TransiveChecker();
}

void test3_2(const void* a, const void* b){
    NewTest();
    if ((Compare(a,b)<0)&&(Compare(b,a)<0))
        SymmetryChecker();
}

void test4(const void* a){
    NewTest();
    if (Compare(a, a)<0||Compare(a, a)>0) 
        ReflexivityChecker();
}
