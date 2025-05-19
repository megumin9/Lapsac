#include <bits/stdc++.h>
using namespace std;

struct TPartitionInfo {
    int* ToBound;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_22(const TPartitionInfo& a, const TPartitionInfo& b) {
    return !b.ToBound || (a.ToBound && *a.ToBound < *b.ToBound);
}

void test1(const TPartitionInfo& a, const TPartitionInfo& b, const TPartitionInfo& c) {
    NewTest();
    if (!compare_22(a,b) && !compare_22(b,c) && compare_22(a,c))
        ConsistencyChecker();
}

void test2(const TPartitionInfo& a, const TPartitionInfo& b, const TPartitionInfo& c) {
    NewTest();
    if (compare_22(a,b) && compare_22(b,c) && compare_22(c,a))
        TransiveChecker();
}

void test3_1(const TPartitionInfo& a, const TPartitionInfo& b) {
    NewTest();
    if (compare_22(a,b) && compare_22(b,a))
        SymmetryChecker();
}

void test3_2(const TPartitionInfo& a, const TPartitionInfo& b) {
    NewTest();
    if (compare_22(a,b) && compare_22(b,a))
        SymmetryChecker();
}

void test4(const TPartitionInfo& a) {
    NewTest();
    if (compare_22(a, a))
        ReflexivityChecker();
}