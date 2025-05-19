#include <bits/stdc++.h>

struct SortAnyByInt {
    int sort_value;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int BLI_sortutil_cmp_int(const void *a_, const void *b_) {
    const SortAnyByInt *a = static_cast<const SortAnyByInt *>(a_);
    const SortAnyByInt *b = static_cast<const SortAnyByInt *>(b_);
    if (a->sort_value > b->sort_value) {
        return 1;
    }
    if (a->sort_value < b->sort_value) {
        return -1;
    }
    return 0;
}

void test1(SortAnyByInt* a, SortAnyByInt* b, SortAnyByInt* c) {
    NewTest();
    if (!(BLI_sortutil_cmp_int(a,b)<0) && !(BLI_sortutil_cmp_int(b,c)<0) && (BLI_sortutil_cmp_int(a,c)<0))
        ConsistencyChecker();
}

void test2(SortAnyByInt* a, SortAnyByInt* b, SortAnyByInt* c) {
    NewTest();
    if ((BLI_sortutil_cmp_int(a,b)<0) && (BLI_sortutil_cmp_int(b,c)<0) && (BLI_sortutil_cmp_int(c,a)<0))
        TransiveChecker();
}

void test3_1(SortAnyByInt* a, SortAnyByInt* b) {
    NewTest();
    if ((BLI_sortutil_cmp_int(a,b)>0)&&(BLI_sortutil_cmp_int(b,a)>0))
        SymmetryChecker();
}

void test3_2(SortAnyByInt* a, SortAnyByInt* b) {
    NewTest();
    if ((BLI_sortutil_cmp_int(a,b)<0)&&(BLI_sortutil_cmp_int(b,a)<0))
        SymmetryChecker();
}

void test4(SortAnyByInt* a) {
    NewTest();
    if (BLI_sortutil_cmp_int(a, a)<0||BLI_sortutil_cmp_int(a, a)>0) 
        ReflexivityChecker();
}