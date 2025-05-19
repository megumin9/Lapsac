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

int CompareAxis0(const void *a, const void *b) {
    const SortType* sa = static_cast<const SortType*>(a);
    const SortType* sb = static_cast<const SortType*>(b);
    if (sa->rects[sa->i].min[0] < sb->rects[sb->i].min[0])
        return -1;
    if (sa->rects[sa->i].min[0] == sb->rects[sb->i].min[0]) {
        if (sa->rects[sa->i].max[0] < sb->rects[sb->i].max[0])
            return -1;
        if (sa->rects[sa->i].max[0] == sb->rects[sb->i].max[0])
            return 0;
        return 1;
    }
    return 1;
}

void test1(const SortType* a, const SortType* b, const SortType* c){
    NewTest();
    if (!(CompareAxis0(a,b) < 0) && !(CompareAxis0(b,c) < 0) && (CompareAxis0(a,c) < 0))
        ConsistencyChecker();
}

void test2(const SortType* a, const SortType* b, const SortType* c){
    NewTest();
    if ((CompareAxis0(a,b) < 0) && (CompareAxis0(b,c) < 0) && (CompareAxis0(c,a) < 0))
        TransiveChecker();
}

void test3_1(const SortType* a, const SortType* b){
    NewTest();
    if ((CompareAxis0(a,b) > 0) && (CompareAxis0(b,a) > 0))
        SymmetryChecker();
}

void test3_2(const SortType* a, const SortType* b){
    NewTest();
    if ((CompareAxis0(a,b) < 0) && (CompareAxis0(b,a) < 0))
        SymmetryChecker();
}

void test4(const SortType* a){
    NewTest();
    if (CompareAxis0(a, a) < 0 || CompareAxis0(a, a) > 0)
        ReflexivityChecker();
}