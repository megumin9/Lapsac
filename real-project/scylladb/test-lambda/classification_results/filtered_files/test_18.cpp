#include <bits/stdc++.h>

struct sstable_run_and_length {
    int second;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(sstable_run_and_length& i, sstable_run_and_length& j) {
    return i.second < j.second;
}

void test1(sstable_run_and_length& a, sstable_run_and_length& b, sstable_run_and_length& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(sstable_run_and_length& a, sstable_run_and_length& b, sstable_run_and_length& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(sstable_run_and_length& a, sstable_run_and_length& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(sstable_run_and_length& a, sstable_run_and_length& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(sstable_run_and_length& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}