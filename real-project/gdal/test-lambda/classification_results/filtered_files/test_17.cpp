
#include <bits/stdc++.h>

struct Item {
    int nodeItem;
};

extern int HILBERT_MAX;
extern int minX;
extern int minY;
extern int width;
extern int height;

uint32_t hilbert(int nodeItem, int HILBERT_MAX, int minX, int minY, int width, int height);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(std::shared_ptr<Item> a, std::shared_ptr<Item> b) {
    uint32_t ha = hilbert(a->nodeItem, HILBERT_MAX, minX, minY, width, height);
    uint32_t hb = hilbert(b->nodeItem, HILBERT_MAX, minX, minY, width, height);
    return ha > hb;
}

void test1(std::shared_ptr<Item> a, std::shared_ptr<Item> b, std::shared_ptr<Item> c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(std::shared_ptr<Item> a, std::shared_ptr<Item> b, std::shared_ptr<Item> c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(std::shared_ptr<Item> a, std::shared_ptr<Item> b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(std::shared_ptr<Item> a, std::shared_ptr<Item> b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(std::shared_ptr<Item> a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}
