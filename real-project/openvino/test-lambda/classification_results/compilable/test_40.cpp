#include <bits/stdc++.h>
using namespace std;

struct BlockDesc {
    vector<size_t> strides;
};
extern BlockDesc blk_desc;
extern vector<size_t> outer_block_dims;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(size_t ind_l, size_t ind_r) {
    return (blk_desc.strides[ind_l] > blk_desc.strides[ind_r]) ||
           (blk_desc.strides[ind_l] == blk_desc.strides[ind_r] &&
            outer_block_dims[ind_l] > outer_block_dims[ind_r]);
}

void test1(size_t a, size_t b, size_t c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(size_t a, size_t b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(size_t a, size_t b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(size_t a){
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}