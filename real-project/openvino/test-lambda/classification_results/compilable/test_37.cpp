#include <bits/stdc++.h>
using namespace std;

struct result_indices {
    int score;
    int batch_index;
    int class_index;
    int box_index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const result_indices& l, const result_indices& r) {
    return (l.score > r.score) || 
           (l.score == r.score && l.batch_index < r.batch_index) ||
           (l.score == r.score && l.batch_index == r.batch_index && l.class_index < r.class_index) ||
           (l.score == r.score && l.batch_index == r.batch_index && 
            l.class_index == r.class_index && l.box_index < r.box_index);
}

void test1(result_indices a, result_indices b, result_indices c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(result_indices a, result_indices b, result_indices c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(result_indices a, result_indices b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(result_indices a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}