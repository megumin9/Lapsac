#include <bits/stdc++.h>
#include <cstdint>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

extern uint32_t* mVertexCoords;

bool lambda3(uint32_t a, uint32_t b) {
    return mVertexCoords[a * 3] < mVertexCoords[b * 3];
}

void test1(uint32_t a, uint32_t b, uint32_t c) {
    NewTest();
    if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c)) 
        ConsistencyChecker();
}

void test2(uint32_t a, uint32_t b, uint32_t c) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a)) 
        TransiveChecker();
}

void test3_1(uint32_t a, uint32_t b) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,a)) 
        SymmetryChecker();
}

void test3_2(uint32_t a, uint32_t b) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,a)) 
        SymmetryChecker();
}

void test4(uint32_t a) {
    NewTest();
    if (lambda3(a, a)) 
        ReflexivityChecker();
}