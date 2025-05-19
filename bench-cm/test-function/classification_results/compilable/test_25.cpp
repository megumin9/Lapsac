#include <bits/stdc++.h>
#include <cstring>

struct ID {
    char* name;
};

int* id_order_get(ID*);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_5(ID* a, ID* b) {
    int* order_a = id_order_get(a);
    int* order_b = id_order_get(b);

    if (order_a && order_b) {
        if (*order_a < *order_b) {
            return true;
        }
        if (*order_a > *order_b) {
            return false;
        }
    }

    return strcmp(a->name, b->name) <= 0;
}

void test1(ID* a, ID* b, ID* c){
    NewTest();
    if (!compare_5(a,b) && !compare_5(b,c) && compare_5(a,c)) 
        ConsistencyChecker();
}

void test2(ID* a, ID* b, ID* c){
    NewTest();
    if (compare_5(a,b) && compare_5(b,c) && compare_5(c,a)) 
        TransiveChecker();
}

void test3_1(ID* a, ID* b){
    NewTest();
    if (compare_5(a,b) && compare_5(b,a))
        SymmetryChecker();
}

void test3_2(ID* a, ID* b){
    NewTest();
    if (compare_5(a,b) && compare_5(b,a))
        SymmetryChecker();
}

void test4(ID* a){
    NewTest();
    if (compare_5(a, a)) 
        ReflexivityChecker();
}