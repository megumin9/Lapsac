#include <bits/stdc++.h>
struct Point {
    int x;
    int ts;
    bool isStart;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_40(Point a, Point b) {
    if (a.x != b.x) {
        return a.x - b.x;
    }
    if (a.ts != b.ts) {
        return a.ts - b.ts;
    }
    if (!a.isStart) {
        return -1; 
    }
    return 1;
}

void test1(Point a, Point b, Point c){
    NewTest();
    if (!(compare_40(a,b)<0) && !(compare_40(b,c)<0) && (compare_40(a,c)<0))
    ConsistencyChecker();
}

void test2(Point a, Point b, Point c){
    NewTest();
    if ((compare_40(a,b)<0) && (compare_40(b,c)<0) && (compare_40(c,a)<0)) 
    TransiveChecker();
}

void test3_1(Point a, Point b){
    NewTest();
    if ((compare_40(a,b)>0)&&(compare_40(b,a)>0))
    SymmetryChecker();
}

void test3_2(Point a, Point b){
    NewTest();
    if ((compare_40(a,b)<0)&&(compare_40(b,a)<0))
    SymmetryChecker();
}

void test4(Point a){
    NewTest();
    if (compare_40(a, a)<0||compare_40(a, a)>0) 
    ReflexivityChecker();
}