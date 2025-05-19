#include <bits/stdc++.h>
using namespace std;

struct MetaFile {
    int frame;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const MetaFile &a, const MetaFile &b) {
    return a.frame < b.frame;
}

void test1(const MetaFile &a, const MetaFile &b, const MetaFile &c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) {
        ConsistencyChecker();
    }
}

void test2(const MetaFile &a, const MetaFile &b, const MetaFile &c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) {
        TransiveChecker();
    }
}

void test3_1(const MetaFile &a, const MetaFile &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) {
        SymmetryChecker();
    }
}

void test4(const MetaFile &a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}