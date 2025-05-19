#include <bits/stdc++.h>

struct DDFIndexedRecord {
    int nKey;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int DDFCompare(const void *pRec1, const void *pRec2) {
    if (((const DDFIndexedRecord *)pRec1)->nKey ==
        ((const DDFIndexedRecord *)pRec2)->nKey)
        return 0;
    if (((const DDFIndexedRecord *)pRec1)->nKey <
        ((const DDFIndexedRecord *)pRec2)->nKey)
        return -1;
    return 1;
}

void test1(const void* a, const void* b, const void* c){
    NewTest();
    if (!(DDFCompare(a,b)<0) && !(DDFCompare(b,c)<0) && (DDFCompare(a,c)<0))
        ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
    NewTest();
    if ((DDFCompare(a,b)<0) && (DDFCompare(b,c)<0) && (DDFCompare(c,a)<0))
        TransiveChecker();
}

void test3_1(const void* a, const void* b){
    NewTest();
    if ((DDFCompare(a,b)<0) && (DDFCompare(b,a)<0))
        SymmetryChecker();
}

void test3_2(const void* a, const void* b){
    NewTest();
    if ((DDFCompare(a,b)>0) && (DDFCompare(b,a)>0))
        SymmetryChecker();
}

void test4(const void* a){
    NewTest();
    if (DDFCompare(a, a)!=0)
        ReflexivityChecker();
}