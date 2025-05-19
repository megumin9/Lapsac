#include <bits/stdc++.h>
using namespace std;

struct float2 {
    int data[2];
    int operator[](size_t index) const { return data[index]; }
};

int round_fl_to_int(int);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int cmp_fn(const void *a, const void *b) {
    return round_fl_to_int((*(float2 *)a)[0] - (*(float2 *)b)[0]);
}

void test1(void *a, void *b, void *c) {
    NewTest();
    if (!(cmp_fn(a,b)<0) && !(cmp_fn(b,c)<0) && (cmp_fn(a,c)<0))
        ConsistencyChecker();
}

void test2(void *a, void *b, void *c) {
    NewTest();
    if ((cmp_fn(a,b)<0) && (cmp_fn(b,c)<0) && (cmp_fn(c,a)<0))
        TransiveChecker();
}

void test3_1(void *a, void *b) {
    NewTest();
    if ((cmp_fn(a,b)>0)&&(cmp_fn(b,a)>0))
        SymmetryChecker();
}

void test3_2(void *a, void *b) {
    NewTest();
    if ((cmp_fn(a,b)<0)&&(cmp_fn(b,a)<0))
        SymmetryChecker();
}

void test4(void *a) {
    NewTest();
    if (cmp_fn(a, a)<0||cmp_fn(a, a)>0)
        ReflexivityChecker();
}