#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct Value {
    int data;
    bool operator<(const Value& other) const { return data < other.data; }
};

bool less(const Value& left, const Value& right) {
    return left < right;
}

void test1(Value a, Value b, Value c){
    NewTest();
    if (!::less(a,b) && !::less(b,c) && ::less(a,c))
    ConsistencyChecker();
}

void test2(Value a, Value b, Value c){
    NewTest();
    if (::less(a,b) && ::less(b,c) && ::less(c,a))
    TransiveChecker();
}

void test3_1(Value a, Value b){
    NewTest();
    if (::less(a,b) && ::less(b,a))
    SymmetryChecker();
}

void test3_2(Value a, Value b){
    NewTest();
    if (::less(a,b) && ::less(b,a))
    SymmetryChecker();
}

void test4(Value a){
    NewTest();
    if (::less(a, a))
    ReflexivityChecker();
}