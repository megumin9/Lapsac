#include <bits/stdc++.h>

namespace gdal {
struct TileMatrixSet {
    struct TileMatrix {
        struct VariableMatrixWidth {
            int mMinTileRow;
        };
    };
};
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &a,
             const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &b) {
    return a.mMinTileRow < b.mMinTileRow;
}

void test1(const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &a,
           const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &b,
           const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
        ConsistencyChecker();
}

void test2(const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &a,
           const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &b,
           const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
        TransiveChecker();
}

void test3_1(const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &a,
             const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test3_2(const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &a,
             const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a))
        SymmetryChecker();
}

void test4(const gdal::TileMatrixSet::TileMatrix::VariableMatrixWidth &a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}