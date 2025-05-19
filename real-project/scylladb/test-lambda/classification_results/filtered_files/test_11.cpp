#include <bits/stdc++.h>
using namespace std;

struct mutation_bounds {
    int lower;
};

bool less(int, int);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const mutation_bounds& a, const mutation_bounds& b) {
    return ::less(a.lower, b.lower);
}

void test1(const mutation_bounds& a, const mutation_bounds& b, const mutation_bounds& c) {
    NewTest();
    if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c)) 
        ConsistencyChecker();
}

void test2(const mutation_bounds& a, const mutation_bounds& b, const mutation_bounds& c) {
    NewTest();
    if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a)) 
        TransiveChecker();
}

void test3_1(const mutation_bounds& a, const mutation_bounds& b) {
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
        SymmetryChecker();
}

void test3_2(const mutation_bounds& a, const mutation_bounds& b) {
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
        SymmetryChecker();
}

void test4(const mutation_bounds& a) {
    NewTest();
    if (lambda2(a, a))
        ReflexivityChecker();
}