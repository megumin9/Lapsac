#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const pair<unsigned int, unsigned int>& p0, const pair<unsigned int, unsigned int>& p1) {
    return p0.first < p1.first;
}

void test1(const pair<unsigned int, unsigned int>& a, const pair<unsigned int, unsigned int>& b, const pair<unsigned int, unsigned int>& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const pair<unsigned int, unsigned int>& a, const pair<unsigned int, unsigned int>& b, const pair<unsigned int, unsigned int>& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const pair<unsigned int, unsigned int>& a, const pair<unsigned int, unsigned int>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(const pair<unsigned int, unsigned int>& a, const pair<unsigned int, unsigned int>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const pair<unsigned int, unsigned int>& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}