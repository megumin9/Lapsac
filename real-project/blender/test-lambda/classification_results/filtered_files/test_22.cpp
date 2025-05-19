#include <bits/stdc++.h>
using namespace std;

struct bNodeLink {
    int multi_input_sort_id;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const bNodeLink *a, const bNodeLink *b) {
    return a->multi_input_sort_id < b->multi_input_sort_id;
}

void test1(const bNodeLink *a, const bNodeLink *b, const bNodeLink *c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const bNodeLink *a, const bNodeLink *b, const bNodeLink *c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const bNodeLink *a, const bNodeLink *b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const bNodeLink *a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}