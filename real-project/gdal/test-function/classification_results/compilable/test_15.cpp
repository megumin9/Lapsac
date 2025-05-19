#include <bits/stdc++.h>
using namespace std;

struct Rect {
    int min[2];
    int max[2];
};

struct SortType {
    Rect* rects;
    int i;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int CompareAxis1(const void *a, const void *b) {
    const SortType* sa = static_cast<const SortType*>(a);
    const SortType* sb = static_cast<const SortType*>(b);
    if (sa->rects[sa->i].min[1] < sb->rects[sb->i].min[1])
        return -1;
    if (sa->rects[sa->i].min[1] == sb->rects[sb->i].min[1])
    {
        if (sa->rects[sa->i].max[1] < sb->rects[sb->i].max[1])
            return -1;
        if (sa->rects[sa->i].max[1] == sb->rects[sb->i].max[1])
            return 0;
        return 1;
    }
    return 1;
}

void test1(const void* a, const void* b, const void* c){
    NewTest();
    if (!(CompareAxis1(a,b)<0) && !(CompareAxis1(b,c)<0) && (CompareAxis1(a,c)<0))
        ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
    NewTest();
    if ((CompareAxis1(a,b)<0) && (CompareAxis1(b,c)<0) && (CompareAxis1(c,a)<0))
        TransiveChecker();
}

void test3_1(const void* a, const void* b){
    NewTest();
    if ((CompareAxis1(a,b)>0)&&(CompareAxis1(b,a)>0))
        SymmetryChecker();
}

void test3_2(const void* a, const void* b){
    NewTest();
    if ((CompareAxis1(a,b)<0)&&(CompareAxis1(b,a)<0))
        SymmetryChecker();
}

void test4(const void* a){
    NewTest();
    if (CompareAxis1(a, a)<0||CompareAxis1(a, a)>0) 
        ReflexivityChecker();
}