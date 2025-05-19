
#include <bits/stdc++.h>
using namespace std;

struct DifferenceCourseBoundary {
    int index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const DifferenceCourseBoundary &a, const DifferenceCourseBoundary &b) {
    return a.index < b.index;
}

void test1(DifferenceCourseBoundary a, DifferenceCourseBoundary b, DifferenceCourseBoundary c) {
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c)) 
        ConsistencyChecker();
}

void test2(DifferenceCourseBoundary a, DifferenceCourseBoundary b, DifferenceCourseBoundary c) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(DifferenceCourseBoundary a, DifferenceCourseBoundary b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(DifferenceCourseBoundary a, DifferenceCourseBoundary b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(DifferenceCourseBoundary a) {
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}
