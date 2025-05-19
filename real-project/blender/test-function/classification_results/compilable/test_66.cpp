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

bool pair_less(const Pair &p1, const Pair &p2) {
    return _comp(p1.second, p2.second);
}

void test1(Pair a, Pair b, Pair c){
    NewTest();
    if (!pair_less(a,b) && !pair_less(b,c) && pair_less(a,c)) 
    ConsistencyChecker();
}

void test2(Pair a, Pair b, Pair c){
    NewTest();
    if (pair_less(a,b) && pair_less(b,c) && pair_less(c,a)) 
    TransiveChecker();
}

void test3_1(Pair a, Pair b){
    NewTest();
    if (pair_less(a,b) && pair_less(b,a))
    SymmetryChecker();
}

void test3_2(Pair a, Pair b){
    NewTest();
    if (pair_less(a,b) && pair_less(b,a))
    SymmetryChecker();
}

void test4(Pair a){
    NewTest();
    if (pair_less(a, a))
    ReflexivityChecker();
}