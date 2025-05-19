#include <bits/stdc++.h>
using namespace std;

struct Pair {
    int second;
};

bool _comp(int, int);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool less(const Pair &p1, const Pair &p2) {
    return _comp(p1.second, p2.second);
}

void test1(Pair a, Pair b, Pair c) {
    NewTest();
    if (!::less(a,b) && !::less(b,c) && ::less(a,c))
        ConsistencyChecker();
}

void test2(Pair a, Pair b, Pair c) {
    NewTest();
    if (::less(a,b) && ::less(b,c) && ::less(c,a))
        TransiveChecker();
}

void test3_1(Pair a, Pair b) {
    NewTest();
    if (::less(a,b) && ::less(b,a))
        SymmetryChecker();
}

void test4(Pair a) {
    NewTest();
    if (::less(a, a))
        ReflexivityChecker();
}