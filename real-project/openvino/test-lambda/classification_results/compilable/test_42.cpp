#include <bits/stdc++.h>
using namespace std;

vector<size_t> refStrides;
vector<size_t> outer_block_dims;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(size_t ind_l, size_t ind_r) {
    return (refStrides[ind_l] > refStrides[ind_r]) ||
           (refStrides[ind_l] == refStrides[ind_r] && outer_block_dims[ind_l] > outer_block_dims[ind_r]);
}

void test1(size_t a, size_t b, size_t c){
    NewTest();
    if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c){
    NewTest();
    if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(size_t a, size_t b){
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test3_2(size_t a, size_t b){
    NewTest();
    if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(size_t a){
    NewTest();
    if (lambda2(a, a))
    ReflexivityChecker();
}