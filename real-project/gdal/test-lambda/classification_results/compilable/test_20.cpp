
#include <bits/stdc++.h>
using namespace std;

struct TileEntry {
    int nTileId;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const TileEntry &a, const TileEntry &b) {
    return a.nTileId < b.nTileId;
}

void test1(TileEntry a, TileEntry b, TileEntry c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(TileEntry a, TileEntry b, TileEntry c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(TileEntry a, TileEntry b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(TileEntry a, TileEntry b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(TileEntry a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}
