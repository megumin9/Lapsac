#include <bits/stdc++.h>
using namespace std;

struct Parc {
    int len;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool pedgeLess(Parc a, Parc b) {
    return a.len < b.len;
}

void test1(Parc a, Parc b, Parc c) {
    NewTest();
    if (!pedgeLess(a,b) && !pedgeLess(b,c) && pedgeLess(a,c))
        ConsistencyChecker();
}

void test2(Parc a, Parc b, Parc c) {
    NewTest();
    if (pedgeLess(a,b) && pedgeLess(b,c) && pedgeLess(c,a))
        TransiveChecker();
}

void test3_1(Parc a, Parc b) {
    NewTest();
    if (pedgeLess(a,b) && pedgeLess(b,a))
        SymmetryChecker();
}

void test3_2(Parc a, Parc b) {
    NewTest();
    if (pedgeLess(a,b) && pedgeLess(b,a))
        SymmetryChecker();
}

void test4(Parc a) {
    NewTest();
    if (pedgeLess(a, a))
        ReflexivityChecker();
}