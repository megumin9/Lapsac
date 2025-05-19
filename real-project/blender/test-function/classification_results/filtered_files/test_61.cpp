
#include <bits/stdc++.h>

struct Value {
    int data;
    bool operator<(const Value& other) const { return data < other.data; }
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool less(const Value& left, const Value& right) {
    return left < right;
}

void test1(const Value& a, const Value& b, const Value& c){
    NewTest();
    if (!less(a,b) && !less(b,c) && less(a,c))
        ConsistencyChecker();
}

void test2(const Value& a, const Value& b, const Value& c){
    NewTest();
    if (less(a,b) && less(b,c) && less(c,a))
        TransiveChecker();
}

void test3_1(const Value& a, const Value& b){
    NewTest();
    if (less(a,b) && less(b,a))
        SymmetryChecker();
}

void test3_2(const Value& a, const Value& b){
    NewTest();
    if (less(a,b) && less(b,a))
        SymmetryChecker();
}

void test4(const Value& a){
    NewTest();
    if (less(a, a))
        ReflexivityChecker();
}
