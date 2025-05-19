#include <bits/stdc++.h>
using namespace std;

struct sPolyExtended {
    double dfArea;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool OGRGeometryFactoryCompareArea(const sPolyExtended &sPoly1,
                                   const sPolyExtended &sPoly2) {
  return sPoly2.dfArea < sPoly1.dfArea;
}

void test1(const sPolyExtended &a, const sPolyExtended &b, const sPolyExtended &c) {
  NewTest();
  if (!OGRGeometryFactoryCompareArea(a, b) && 
      !OGRGeometryFactoryCompareArea(b, c) && 
      OGRGeometryFactoryCompareArea(a, c)) {
    ConsistencyChecker();
  }
}

void test2(const sPolyExtended &a, const sPolyExtended &b, const sPolyExtended &c) {
  NewTest();
  if (OGRGeometryFactoryCompareArea(a, b) && 
      OGRGeometryFactoryCompareArea(b, c) && 
      OGRGeometryFactoryCompareArea(c, a)) {
    TransiveChecker();
  }
}

void test3_1(const sPolyExtended &a, const sPolyExtended &b) {
  NewTest();
  if (OGRGeometryFactoryCompareArea(a, b) && 
      OGRGeometryFactoryCompareArea(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(const sPolyExtended &a, const sPolyExtended &b) {
  NewTest();
  if (OGRGeometryFactoryCompareArea(a, b) && 
      OGRGeometryFactoryCompareArea(b, a)) {
    SymmetryChecker();
  }
}

void test4(const sPolyExtended &a) {
  NewTest();
  if (OGRGeometryFactoryCompareArea(a, a)) {
    ReflexivityChecker();
  }
}