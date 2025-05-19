#include <bits/stdc++.h>
struct event {
    int time;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(const event& o1, const event& o2) {
    return o1.time > o2.time;
}

void test1(event a, event b, event c){
    NewTest();
    if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
    ConsistencyChecker();
}

void test2(event a, event b, event c){
    NewTest();
    if (cmp(a,b) && cmp(b,c) && cmp(c,a))
    TransiveChecker();
}

void test3_1(event a, event b){
    NewTest();
    if (cmp(a,b) && cmp(b,a))
    SymmetryChecker();
}

void test3_2(event a, event b){
    NewTest();
    if (cmp(a,b) && cmp(b,a))
    SymmetryChecker();
}

void test4(event a){
    NewTest();
    if (cmp(a, a))
    ReflexivityChecker();
}