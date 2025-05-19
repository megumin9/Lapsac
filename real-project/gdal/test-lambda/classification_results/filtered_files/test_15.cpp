#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

struct Point {
    int x;
    int y;
};

struct ITEM_TYPE {
    Point nodeItem;
};

uint32_t HILBERT_MAX, minX, minY, width, height;

uint32_t hilbert(Point nodeItem, uint32_t HILBERT_MAX, uint32_t minX, uint32_t minY, uint32_t width, uint32_t height);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ITEM_TYPE &a, const ITEM_TYPE &b) {
    uint32_t ha = hilbert(a.nodeItem, HILBERT_MAX, minX, minY, width, height);
    uint32_t hb = hilbert(b.nodeItem, HILBERT_MAX, minX, minY, width, height);
    return ha > hb;
}

void test1(ITEM_TYPE a, ITEM_TYPE b, ITEM_TYPE c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(ITEM_TYPE a, ITEM_TYPE b, ITEM_TYPE c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(ITEM_TYPE a, ITEM_TYPE b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(ITEM_TYPE a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}