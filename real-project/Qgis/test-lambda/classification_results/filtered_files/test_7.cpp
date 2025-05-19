#include <bits/stdc++.h>
using namespace std;

struct FileInfo {
    int numPoints;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const FileInfo& f1, const FileInfo& f2) {
    return f1.numPoints > f2.numPoints;
}

void test1(const FileInfo& a, const FileInfo& b, const FileInfo& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const FileInfo& a, const FileInfo& b, const FileInfo& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const FileInfo& a, const FileInfo& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const FileInfo& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}