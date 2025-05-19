#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(const Point* a, const Point* b) {
    if (a->y < b->y) {
        return true;
    } else if (a->y == b->y) {
        if (a->x < b->x) {
            return true;
        }
    }
    return false;
}

void test1(const Point* a, const Point* b, const Point* c){
    NewTest();
    if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
    ConsistencyChecker();
}

void test2(const Point* a, const Point* b, const Point* c){
    NewTest();
    if (cmp(a,b) && cmp(b,c) && cmp(c,a))
    TransiveChecker();
}

void test3_1(const Point* a, const Point* b){
    NewTest();
    if (cmp(a,b) && cmp(b,a))
    SymmetryChecker();
}

void test3_2(const Point* a, const Point* b){
    NewTest();
    if (cmp(a,b) && cmp(b,a))
    SymmetryChecker();
}

void test4(const Point* a){
    NewTest();
    if (cmp(a, a))
    ReflexivityChecker();
}