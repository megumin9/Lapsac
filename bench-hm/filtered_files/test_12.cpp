#include <bits/stdc++.h>

struct testclass {
    bool var5;
    std::vector<int> var3;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(testclass *a, testclass *b) {
    if (a->var5 && b->var5)
        return a->var3.size() < b->var3.size();
    return false;
}

void test1(testclass* a, testclass* b, testclass* c){
    NewTest();
    if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
        ConsistencyChecker();
}

void test2(testclass* a, testclass* b, testclass* c){
    NewTest();
    if (cmp(a,b) && cmp(b,c) && cmp(c,a))
        TransiveChecker();
}

void test3_1(testclass* a, testclass* b){
    NewTest();
    if (cmp(a,b) && cmp(b,a))
        SymmetryChecker();
}

void test3_2(testclass* a, testclass* b){
    NewTest();
    if (cmp(a,b) && cmp(b,a))
        SymmetryChecker();
}

void test4(testclass* a){
    NewTest();
    if (cmp(a, a))
        ReflexivityChecker();
}