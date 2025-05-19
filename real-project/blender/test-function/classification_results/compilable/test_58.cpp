#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct Value {
    int data;
    Value(int d = 0) : data(d) {}
    Value operator+(int eps) const { return Value(data + eps); }
    bool operator<(const Value& other) const { return data < other.data; }
};

extern int _epsilon;

bool less(Value a, Value b) {
    return a + _epsilon < b;
}

void test1(Value a, Value b, Value c) {
    NewTest();
    if (!::less(a,b) && !::less(b,c) && ::less(a,c))
        ConsistencyChecker();
}

void test2(Value a, Value b, Value c) {
    NewTest();
    if (::less(a,b) && ::less(b,c) && ::less(c,a))
        TransiveChecker();
}

void test3_1(Value a, Value b) {
    NewTest();
    if (::less(a,b) && ::less(b,a))
        SymmetryChecker();
}

void test4(Value a) {
    NewTest();
    if (::less(a, a))
        ReflexivityChecker();
}