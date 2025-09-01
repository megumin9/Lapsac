#include <bits/stdc++.h>
using namespace std;

struct UpdateItem {
    int priority;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_25(const UpdateItem &item1, const UpdateItem &item2) {
    return (item1.priority - item2.priority < 0) ? false : true;
}

void test1(const UpdateItem &a, const UpdateItem &b, const UpdateItem &c){
    NewTest();
    if (!compare_25(a,b) && !compare_25(b,c) && compare_25(a,c)) 
        ConsistencyChecker();
}

void test2(const UpdateItem &a, const UpdateItem &b, const UpdateItem &c){
    NewTest();
    if (compare_25(a,b) && compare_25(b,c) && compare_25(c,a)) 
        TransiveChecker();
}

void test3_1(const UpdateItem &a, const UpdateItem &b){
    NewTest();
    if (compare_25(a,b) && compare_25(b,a))
        SymmetryChecker();
}

void test3_2(const UpdateItem &a, const UpdateItem &b){
    NewTest();
    if (compare_25(a,b) && compare_25(b,a))
        SymmetryChecker();
}

void test4(const UpdateItem &a){
    NewTest();
    if (compare_25(a, a)) 
        ReflexivityChecker();
}