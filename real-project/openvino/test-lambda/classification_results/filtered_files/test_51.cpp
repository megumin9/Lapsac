#include <bits/stdc++.h>
using namespace std;

struct Attrs {
    int start;
    int stop;
};

struct SliceWithAttrs {
    Attrs attrs;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const SliceWithAttrs& lhs, const SliceWithAttrs& rhs) {
    if (lhs.attrs.start == rhs.attrs.start)
        return lhs.attrs.stop < rhs.attrs.stop;
    return lhs.attrs.start < rhs.attrs.start;
}

void test1(SliceWithAttrs a, SliceWithAttrs b, SliceWithAttrs c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c)) 
        ConsistencyChecker();
}

void test2(SliceWithAttrs a, SliceWithAttrs b, SliceWithAttrs c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a)) 
        TransiveChecker();
}

void test3_1(SliceWithAttrs a, SliceWithAttrs b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(SliceWithAttrs a){
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}