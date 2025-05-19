#include <bits/stdc++.h>
using namespace std;

typedef int Value;
extern Value _epsilon;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool my_less(Value a, Value b) {
    return a + _epsilon < b;
}

void test1(Value a, Value b, Value c){
    NewTest();
    if (!my_less(a,b) && !my_less(b,c) && my_less(a,c))
        ConsistencyChecker();
}

void test2(Value a, Value b, Value c){
    NewTest();
    if (my_less(a,b) && my_less(b,c) && my_less(c,a))
        TransiveChecker();
}

void test3_1(Value a, Value b){
    NewTest();
    if (my_less(a,b) && my_less(b,a))
        SymmetryChecker();
}

void test3_2(Value a, Value b){
    NewTest();
    if (my_less(a,b) && my_less(b,a))
        SymmetryChecker();
}

void test4(Value a){
    NewTest();
    if (my_less(a, a))
        ReflexivityChecker();
}