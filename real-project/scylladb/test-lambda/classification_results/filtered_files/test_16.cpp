#include <bits/stdc++.h>

struct perf_result {};
int get_stat(const perf_result&);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const perf_result& a, const perf_result& b) {
    return get_stat(a) < get_stat(b);
}

void test1(const perf_result& a, const perf_result& b, const perf_result& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const perf_result& a, const perf_result& b, const perf_result& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const perf_result& a, const perf_result& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const perf_result& a, const perf_result& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const perf_result& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}