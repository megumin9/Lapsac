
#include <bits/stdc++.h>

extern int* adfX;
extern int* adfY;
extern int dfX;
extern int dfY;
int SQ(int);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(int i1, int i2) {
    return SQ(adfX[i1] - dfX) + SQ(adfY[i1] - dfY) < 
           SQ(adfX[i2] - dfX) + SQ(adfY[i2] - dfY);
}

void test1(int a, int b, int c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(int a, int b, int c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(int a, int b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(int a, int b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(int a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}
