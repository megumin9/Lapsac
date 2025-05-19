#include <bits/stdc++.h>

struct rgba {
    uint8_t a, r, g, b;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_24(const rgba& x, const rgba& y) {
    int t1 = (int)x.a + x.r + x.g + x.b;
    int t2 = (int)y.a + y.r + y.g + y.b;
    if (t1 != t2) return t1 < t2;

    return (((int)x.a - y.a) >> 24) +
        (((int)x.r - y.r) >> 16) +
        (((int)x.g - y.g) >> 8) +
        ((int)x.b - y.b);
}

void test1(rgba a, rgba b, rgba c){
    NewTest();
    if (!compare_24(a,b) && !compare_24(b,c) && compare_24(a,c)) 
        ConsistencyChecker();
}

void test2(rgba a, rgba b, rgba c){
    NewTest();
    if (compare_24(a,b) && compare_24(b,c) && compare_24(c,a)) 
        TransiveChecker();
}

void test3_1(rgba a, rgba b){
    NewTest();
    if (compare_24(a,b) && compare_24(b,a))
        SymmetryChecker();
}

void test3_2(rgba a, rgba b){
    NewTest();
    if (compare_24(a,b) && compare_24(b,a))
        SymmetryChecker();
}

void test4(rgba a){
    NewTest();
    if (compare_24(a, a)) 
        ReflexivityChecker();
}