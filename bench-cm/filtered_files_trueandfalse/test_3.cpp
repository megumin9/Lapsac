
#include <bits/stdc++.h>
using namespace std;

struct MyStruct {
    string first;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_2(const MyStruct& p1, const MyStruct& p2) {
    return p1.first.compare(p2.first) <= 0;
}

void test1(MyStruct a, MyStruct b, MyStruct c){
    NewTest();
    if (!compare_2(a,b) && !compare_2(b,c) && compare_2(a,c)) 
        ConsistencyChecker();
}

void test2(MyStruct a, MyStruct b, MyStruct c){
    NewTest();
    if (compare_2(a,b) && compare_2(b,c) && compare_2(c,a)) 
        TransiveChecker();
}

void test3_1(MyStruct a, MyStruct b){
    NewTest();
    if (compare_2(a,b) && compare_2(b,a))
        SymmetryChecker();
}

void test3_2(MyStruct a, MyStruct b){
    NewTest();
    if (compare_2(a,b) && compare_2(b,a))
        SymmetryChecker();
}

void test4(MyStruct a){
    NewTest();
    if (compare_2(a, a))
        ReflexivityChecker();
}
