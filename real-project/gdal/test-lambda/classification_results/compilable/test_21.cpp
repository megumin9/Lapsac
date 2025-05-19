#include <bits/stdc++.h>
using namespace std;

struct SortType { int i; };
struct Rect { int min[1], max[1]; };
struct Node { vector<Rect> rects; };
Node nodeOri;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const SortType& a, const SortType& b) {
    return nodeOri.rects[a.i].min[0] < nodeOri.rects[b.i].min[0] ||
           (nodeOri.rects[a.i].min[0] == nodeOri.rects[b.i].min[0] &&
            nodeOri.rects[a.i].max[0] < nodeOri.rects[b.i].max[0]);
}

void test1(SortType a, SortType b, SortType c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(SortType a, SortType b, SortType c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(SortType a, SortType b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(SortType a){
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}