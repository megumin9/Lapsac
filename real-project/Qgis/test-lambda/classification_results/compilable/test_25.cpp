
#include <bits/stdc++.h>
#include <cstdint>

uint32_t* mVertexCoords;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(uint32_t a, uint32_t b) {
    return mVertexCoords[a * 3 + 1] < mVertexCoords[b * 3 + 1];
}

void test1(uint32_t a, uint32_t b, uint32_t c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(uint32_t a, uint32_t b, uint32_t c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(uint32_t a, uint32_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(uint32_t a) {
    NewTest();
    if (lambda0(a,a))
        ReflexivityChecker();
}
