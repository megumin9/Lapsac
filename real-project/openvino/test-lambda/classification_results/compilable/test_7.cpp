#include <bits/stdc++.h>
using namespace std;

struct BoxInfo {
    int class_index;
    int batch_index;
    int score;
    int index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const BoxInfo& l, const BoxInfo& r) {
    return (l.class_index < r.class_index) ||
           (l.class_index == r.class_index && l.batch_index < r.batch_index) ||
           (l.class_index == r.class_index && l.batch_index == r.batch_index && l.score > r.score) ||
           (l.class_index == r.class_index && l.batch_index == r.batch_index && l.score == r.score &&
            l.index < r.index);
}

void test1(BoxInfo a, BoxInfo b, BoxInfo c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
        ConsistencyChecker();
}

void test2(BoxInfo a, BoxInfo b, BoxInfo c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(BoxInfo a, BoxInfo b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(BoxInfo a, BoxInfo b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(BoxInfo a){
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}