#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool my_less(int left, int right) {
    return left < right;
}

void test1(int a, int b, int c){
    NewTest();
    if (!my_less(a,b) && !my_less(b,c) && my_less(a,c))
    ConsistencyChecker();
}

void test2(int a, int b, int c){
    NewTest();
    if (my_less(a,b) && my_less(b,c) && my_less(c,a))
    TransiveChecker();
}

void test3_1(int a, int b){
    NewTest();
    if (my_less(a,b) && my_less(b,a))
    SymmetryChecker();
}

void test3_2(int a, int b){
    NewTest();
    if (my_less(a,b) && my_less(b,a))
    SymmetryChecker();
}

void test4(int a){
    NewTest();
    if (my_less(a, a))
    ReflexivityChecker();
}