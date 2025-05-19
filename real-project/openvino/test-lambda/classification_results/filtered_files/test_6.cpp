#include <bits/stdc++.h>
using namespace std;

struct BoxInfo {
    int score;
    int batch_index;
    int class_index;
    int index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const BoxInfo& l, const BoxInfo& r) {
    return (l.score > r.score) || (l.score == r.score && l.batch_index < r.batch_index) ||
           (l.score == r.score && l.batch_index == r.batch_index && l.class_index < r.class_index) ||
           (l.score == r.score && l.batch_index == r.batch_index && l.class_index == r.class_index && l.index < r.index);
}

void test1(BoxInfo a, BoxInfo b, BoxInfo c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(BoxInfo a, BoxInfo b, BoxInfo c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(BoxInfo a, BoxInfo b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(BoxInfo a, BoxInfo b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(BoxInfo a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}