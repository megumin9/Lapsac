#include <bits/stdc++.h>
using namespace std;

struct AssetItem {
    string osDateTime;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const AssetItem &a, const AssetItem &b) {
    if (!a.osDateTime.empty() && !b.osDateTime.empty())
        return a.osDateTime < b.osDateTime;
    return &a < &b;
}

void test1(AssetItem a, AssetItem b, AssetItem c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(AssetItem a, AssetItem b, AssetItem c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(AssetItem a, AssetItem b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(AssetItem a, AssetItem b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(AssetItem a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}