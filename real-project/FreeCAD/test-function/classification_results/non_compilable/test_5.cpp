#include <bits/stdc++.h>
#include <TopoDS/TopoDS_Wire.hxx>
#include <ShapeAnalysis_ContourArea.hxx>

class EdgeWalker {
public:
    static bool wireCompare(const TopoDS_Wire& w1, const TopoDS_Wire& w2);
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool EdgeWalker::wireCompare(const TopoDS_Wire& w1, const TopoDS_Wire& w2) {
    int area1 = static_cast<int>(ShapeAnalysis_ContourArea::ContourArea(w1));
    int area2 = static_cast<int>(ShapeAnalysis_ContourArea::ContourArea(w2));
    return area1 > area2;
}

void test1(TopoDS_Wire& a, TopoDS_Wire& b, TopoDS_Wire& c){
    NewTest();
    if (!EdgeWalker::wireCompare(a,b) && !EdgeWalker::wireCompare(b,c) && EdgeWalker::wireCompare(a,c))
        ConsistencyChecker();
}

void test2(TopoDS_Wire& a, TopoDS_Wire& b, TopoDS_Wire& c){
    NewTest();
    if (EdgeWalker::wireCompare(a,b) && EdgeWalker::wireCompare(b,c) && EdgeWalker::wireCompare(c,a))
        TransiveChecker();
}

void test3_1(TopoDS_Wire& a, TopoDS_Wire& b){
    NewTest();
    if (EdgeWalker::wireCompare(a,b) && EdgeWalker::wireCompare(b,a))
        SymmetryChecker();
}

void test3_2(TopoDS_Wire& a, TopoDS_Wire& b){
    NewTest();
    if (EdgeWalker::wireCompare(a,b) && EdgeWalker::wireCompare(b,a))
        SymmetryChecker();
}

void test4(TopoDS_Wire& a){
    NewTest();
    if (EdgeWalker::wireCompare(a, a))
        ReflexivityChecker();
}