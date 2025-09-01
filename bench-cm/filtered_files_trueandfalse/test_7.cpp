#include <bits/stdc++.h>
using namespace std;

struct NewCollision {
    int first;
    int second;
    int colldata;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_14(const NewCollision &a, const NewCollision &b) {
    return a.first < b.first || a.second < b.second || a.colldata < b.colldata;
}

void test1(NewCollision a, NewCollision b, NewCollision c){
    NewTest();
    if (!compare_14(a,b) && !compare_14(b,c) && compare_14(a,c))
        ConsistencyChecker();
}

void test2(NewCollision a, NewCollision b, NewCollision c){
    NewTest();
    if (compare_14(a,b) && compare_14(b,c) && compare_14(c,a))
        TransiveChecker();
}

void test3_1(NewCollision a, NewCollision b){
    NewTest();
    if (compare_14(a,b) && compare_14(b,a))
        SymmetryChecker();
}

void test3_2(NewCollision a, NewCollision b){
    NewTest();
    if (compare_14(a,b) && compare_14(b,a))
        SymmetryChecker();
}

void test4(NewCollision a){
    NewTest();
    if (compare_14(a, a))
        ReflexivityChecker();
}