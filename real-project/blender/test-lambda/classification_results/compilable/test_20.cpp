#include <bits/stdc++.h>
using namespace std;

struct CacheFrame {
    int framenr;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const CacheFrame &a, const CacheFrame &b) {
    return a.framenr < b.framenr;
}

void test1(const CacheFrame &a, const CacheFrame &b, const CacheFrame &c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) 
        ConsistencyChecker();
}

void test2(const CacheFrame &a, const CacheFrame &b, const CacheFrame &c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) 
        TransiveChecker();
}

void test3_1(const CacheFrame &a, const CacheFrame &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) 
        SymmetryChecker();
}

void test3_2(const CacheFrame &a, const CacheFrame &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) 
        SymmetryChecker();
}

void test4(const CacheFrame &a) {
    NewTest();
    if (lambda0(a, a)) 
        ReflexivityChecker();
}