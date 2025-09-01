#include <bits/stdc++.h>

struct RESOLUTION_WHR {
    int width;
    int height;
    int flags;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_10(RESOLUTION_WHR i, RESOLUTION_WHR j) {
    return (i.width < j.width
            || (i.width == j.width && i.height < j.height)
            || (i.width == j.width && i.height == j.height && i.flags != j.flags));
}

void test1(RESOLUTION_WHR a, RESOLUTION_WHR b, RESOLUTION_WHR c){
    NewTest();
    if (!compare_10(a,b) && !compare_10(b,c) && compare_10(a,c)) 
        ConsistencyChecker();
}

void test2(RESOLUTION_WHR a, RESOLUTION_WHR b, RESOLUTION_WHR c){
    NewTest();
    if (compare_10(a,b) && compare_10(b,c) && compare_10(c,a)) 
        TransiveChecker();
}

void test3_1(RESOLUTION_WHR a, RESOLUTION_WHR b){
    NewTest();
    if (compare_10(a,b) && compare_10(b,a))
        SymmetryChecker();
}

void test3_2(RESOLUTION_WHR a, RESOLUTION_WHR b){
    NewTest();
    if (compare_10(a,b) && compare_10(b,a))
        SymmetryChecker();
}

void test4(RESOLUTION_WHR a){
    NewTest();
    if (compare_10(a, a))
        ReflexivityChecker();
}