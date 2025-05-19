
#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int SHPTreeCompareInts(const void *a, const void *b) {
    return *reinterpret_cast<const int*>(a) - *reinterpret_cast<const int*>(b);
}

void test1(int a, int b, int c) {
    NewTest();
    if (SHPTreeCompareInts(&a, &b) >= 0 && SHPTreeCompareInts(&b, &c) >= 0 && SHPTreeCompareInts(&a, &c) < 0)
        ConsistencyChecker();
}

void test2(int a, int b, int c) {
    NewTest();
    if (SHPTreeCompareInts(&a, &b) < 0 && SHPTreeCompareInts(&b, &c) < 0 && SHPTreeCompareInts(&c, &a) < 0)
        TransiveChecker();
}

void test3_2(int a, int b) {
    NewTest();
    if (SHPTreeCompareInts(&a, &b) < 0 && SHPTreeCompareInts(&b, &a) < 0)
        SymmetryChecker();
}

void test4(int a) {
    NewTest();
    if (SHPTreeCompareInts(&a, &a) < 0 || SHPTreeCompareInts(&a, &a) > 0)
        ReflexivityChecker();
}
