#include <bits/stdc++.h>

struct SortType {
    int i;
};

struct Rect {
    int min[2];
    int max[2];
};

struct NodeOriType {
    std::vector<Rect> rects;
};

extern NodeOriType nodeOri;
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const SortType& a, const SortType& b) {
    return nodeOri.rects[a.i].min[1] < nodeOri.rects[b.i].min[1] ||
           (nodeOri.rects[a.i].min[1] == nodeOri.rects[b.i].min[1] &&
            nodeOri.rects[a.i].max[1] < nodeOri.rects[b.i].max[1]);
}

void test1(const SortType& a, const SortType& b, const SortType& c) {
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const SortType& a, const SortType& b, const SortType& c) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const SortType& a, const SortType& b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(const SortType& a, const SortType& b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const SortType& a) {
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}