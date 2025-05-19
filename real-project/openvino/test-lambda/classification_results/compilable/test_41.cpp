#include <bits/stdc++.h>
using namespace std;

vector<size_t> actualStrides;
vector<size_t> outer_block_dims;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(size_t ind_l, size_t ind_r) {
    return (actualStrides[ind_l] > actualStrides[ind_r]) ||
           (actualStrides[ind_l] == actualStrides[ind_r] &&
            outer_block_dims[ind_l] > outer_block_dims[ind_r]);
}

void test1(size_t a, size_t b, size_t c) {
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
        ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(size_t a, size_t b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(size_t a, size_t b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(size_t a) {
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}