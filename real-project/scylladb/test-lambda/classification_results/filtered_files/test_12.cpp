#include <bits/stdc++.h>
using namespace std;

struct reader_bounds {
    int lower;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();
bool less(int a, int b);

bool lambda3(const reader_bounds& a, const reader_bounds& b) {
    return ::less(a.lower, b.lower);
}

void test1(reader_bounds a, reader_bounds b, reader_bounds c){
    NewTest();
    if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c)) 
    ConsistencyChecker();
}

void test2(reader_bounds a, reader_bounds b, reader_bounds c){
    NewTest();
    if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a)) 
    TransiveChecker();
}

void test3_1(reader_bounds a, reader_bounds b){
    NewTest();
    if (lambda3(a,b) && lambda3(b,a))
    SymmetryChecker();
}

void test3_2(reader_bounds a, reader_bounds b){
    NewTest();
    if (lambda3(a,b) && lambda3(b,a))
    SymmetryChecker();
}

void test4(reader_bounds a){
    NewTest();
    if (lambda3(a, a))
    ReflexivityChecker();
}