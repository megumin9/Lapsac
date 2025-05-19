#include <bits/stdc++.h>

struct splitPoint {
    int i;
    int param;
};

class DrawProjectSplit {
public:
    static bool splitCompare(const splitPoint& p1, const splitPoint& p2);
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool DrawProjectSplit::splitCompare(const splitPoint& p1, const splitPoint& p2) {
    if (p1.i > p2.i) {
        return true;
    } else if (p1.i < p2.i) {
        return false;
    } else if (p1.param > p2.param) {
        return true;
    } else if (p1.param < p2.param) {
        return false;
    }
    return false;
}

void test1(splitPoint a,splitPoint b,splitPoint c){
NewTest();
if (!DrawProjectSplit::splitCompare(a,b) &&!DrawProjectSplit::splitCompare(b,c) && DrawProjectSplit::splitCompare(a,c))
ConsistencyChecker();
}

void test2(splitPoint a,splitPoint b,splitPoint c){
NewTest();
if (DrawProjectSplit::splitCompare(a,b) && DrawProjectSplit::splitCompare(b,c) && DrawProjectSplit::splitCompare(c,a))
TransiveChecker();
}

void test3_1(splitPoint a,splitPoint b){
NewTest();
if (DrawProjectSplit::splitCompare(a,b) && DrawProjectSplit::splitCompare(b,a))
SymmetryChecker();
}

void test3_2(splitPoint a,splitPoint b){
NewTest();
if (DrawProjectSplit::splitCompare(a,b) && DrawProjectSplit::splitCompare(b,a))
SymmetryChecker();
}

void test4(splitPoint a){
NewTest();
if (DrawProjectSplit::splitCompare(a, a))
ReflexivityChecker();
}