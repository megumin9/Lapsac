#include <bits/stdc++.h>
using namespace std;

struct GDALWarpChunk {
    int dx;
    int dy;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const GDALWarpChunk &a, const GDALWarpChunk &b) {
    if (a.dy < b.dy)
        return true;
    if (a.dy > b.dy)
        return false;
    return a.dx < b.dx;
}

void test1(GDALWarpChunk a, GDALWarpChunk b, GDALWarpChunk c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(GDALWarpChunk a, GDALWarpChunk b, GDALWarpChunk c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(GDALWarpChunk a, GDALWarpChunk b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(GDALWarpChunk a, GDALWarpChunk b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(GDALWarpChunk a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}