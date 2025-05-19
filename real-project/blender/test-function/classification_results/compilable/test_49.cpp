#include <bits/stdc++.h>
using bigit = uint32_t;

class bigint {
public:
    int num_bigits() const;
    bigit operator[](int index) const;
    std::vector<bigit> bigits_;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare(const bigint& lhs, const bigint& rhs) {
    int num_lhs_bigits = lhs.num_bigits(), num_rhs_bigits = rhs.num_bigits();
    if (num_lhs_bigits != num_rhs_bigits)
        return num_lhs_bigits > num_rhs_bigits ? 1 : -1;
    int i = static_cast<int>(lhs.bigits_.size()) - 1;
    int j = static_cast<int>(rhs.bigits_.size()) - 1;
    int end = i - j;
    if (end < 0) end = 0;
    for (; i >= end; --i, --j) {
        bigit lhs_bigit = lhs[i], rhs_bigit = rhs[j];
        if (lhs_bigit != rhs_bigit) return lhs_bigit > rhs_bigit ? 1 : -1;
    }
    if (i != j) return i > j ? 1 : -1;
    return 0;
}

void test1(bigint a, bigint b, bigint c) {
    NewTest();
    if (!(compare(a,b)<0) && !(compare(b,c)<0) && (compare(a,c)<0))
    ConsistencyChecker();
}

void test2(bigint a, bigint b, bigint c) {
    NewTest();
    if ((compare(a,b)<0) && (compare(b,c)<0) && (compare(c,a)<0))
    TransiveChecker();
}

void test3_1(bigint a, bigint b) {
    NewTest();
    if ((compare(a,b)>0)&&(compare(b,a)>0))
    SymmetryChecker();
}

void test3_2(bigint a, bigint b) {
    NewTest();
    if ((compare(a,b)<0)&&(compare(b,a)<0))
    SymmetryChecker();
}

void test4(bigint a) {
    NewTest();
    if (compare(a, a)<0||compare(a, a)>0)
    ReflexivityChecker();
}