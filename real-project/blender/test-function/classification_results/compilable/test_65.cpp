#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool less(int left, int right) {
    return left > right;
}

void test1(int a, int b, int c) {
    NewTest();
    if (!less(a,b) && !less(b,c) && less(a,c))
    ConsistencyChecker();
}

void test2(int a, int b, int c) {
    NewTest();
    if (less(a,b) && less(b,c) && less(c,a))
    TransiveChecker();
}

void test3_1(int a, int b) {
    NewTest();
    if (less(a,b) && less(b,a))
    SymmetryChecker();
}

void test3_2(int a, int b) {
    NewTest();
    if (less(a,b) && less(b,a))
    SymmetryChecker();
}

void test4(int a) {
    NewTest();
    if (less(a, a))
    ReflexivityChecker();
}