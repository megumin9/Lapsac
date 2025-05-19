#include <bits/stdc++.h>

struct sPolyExtended {
    int nInitialIndex;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool OGRGeometryFactoryCompareByIndex(const sPolyExtended &sPoly1, const sPolyExtended &sPoly2) {
    return sPoly1.nInitialIndex < sPoly2.nInitialIndex;
}

void test1(const sPolyExtended &a, const sPolyExtended &b, const sPolyExtended &c) {
    NewTest();
    if (!OGRGeometryFactoryCompareByIndex(a,b) && !OGRGeometryFactoryCompareByIndex(b,c) && OGRGeometryFactoryCompareByIndex(a,c))
        ConsistencyChecker();
}

void test2(const sPolyExtended &a, const sPolyExtended &b, const sPolyExtended &c) {
    NewTest();
    if (OGRGeometryFactoryCompareByIndex(a,b) && OGRGeometryFactoryCompareByIndex(b,c) && OGRGeometryFactoryCompareByIndex(c,a))
        TransiveChecker();
}

void test3_1(const sPolyExtended &a, const sPolyExtended &b) {
    NewTest();
    if (OGRGeometryFactoryCompareByIndex(a,b) && OGRGeometryFactoryCompareByIndex(b,a))
        SymmetryChecker();
}

void test3_2(const sPolyExtended &a, const sPolyExtended &b) {
    NewTest();
    if (OGRGeometryFactoryCompareByIndex(a,b) && OGRGeometryFactoryCompareByIndex(b,a))
        SymmetryChecker();
}

void test4(const sPolyExtended &a) {
    NewTest();
    if (OGRGeometryFactoryCompareByIndex(a, a))
        ReflexivityChecker();
}