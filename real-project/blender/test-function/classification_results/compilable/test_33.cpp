#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

enum { TOP, LEFT };

struct But {
    int alignnr;
};

struct ButAlign {
    But* but;
    int* borders[2];
};

int ui_block_align_butal_cmp(const void* a, const void* b) {
    const ButAlign* butal = static_cast<const ButAlign*>(a);
    const ButAlign* butal_other = static_cast<const ButAlign*>(b);

    if (butal->but->alignnr != butal_other->but->alignnr) {
        return butal->but->alignnr - butal_other->but->alignnr;
    }

    if (*butal->borders[TOP] != *butal_other->borders[TOP]) {
        return (*butal_other->borders[TOP] > *butal->borders[TOP]) ? 1 : -1;
    }

    if (*butal->borders[LEFT] != *butal_other->borders[LEFT]) {
        return (*butal->borders[LEFT] > *butal_other->borders[LEFT]) ? 1 : -1;
    }

    return 0;
}

void test1(void* a, void* b, void* c) {
    NewTest();
    if (!(ui_block_align_butal_cmp(a, b) < 0) && !(ui_block_align_butal_cmp(b, c) < 0) && (ui_block_align_butal_cmp(a, c) < 0))
        ConsistencyChecker();
}

void test2(void* a, void* b, void* c) {
    NewTest();
    if ((ui_block_align_butal_cmp(a, b) < 0) && (ui_block_align_butal_cmp(b, c) < 0) && (ui_block_align_butal_cmp(c, a) < 0))
        TransiveChecker();
}

void test3_1(void* a, void* b) {
    NewTest();
    if ((ui_block_align_butal_cmp(a, b) > 0) && (ui_block_align_butal_cmp(b, a) > 0))
        SymmetryChecker();
}

void test3_2(void* a, void* b) {
    NewTest();
    if ((ui_block_align_butal_cmp(a, b) < 0) && (ui_block_align_butal_cmp(b, a) < 0))
        SymmetryChecker();
}

void test4(void* a) {
    NewTest();
    if (ui_block_align_butal_cmp(a, a) < 0 || ui_block_align_butal_cmp(a, a) > 0)
        ReflexivityChecker();
}