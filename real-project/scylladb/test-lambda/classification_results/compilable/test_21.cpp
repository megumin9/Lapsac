#include <bits/stdc++.h>

namespace sstables {
struct sstable {
    int data_size() const;
};
using shared_sstable = sstable*;
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(sstables::shared_sstable& a, sstables::shared_sstable& b) {
    return a->data_size() > b->data_size();
}

void test1(sstables::shared_sstable& a, sstables::shared_sstable& b, sstables::shared_sstable& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(sstables::shared_sstable& a, sstables::shared_sstable& b, sstables::shared_sstable& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(sstables::shared_sstable& a, sstables::shared_sstable& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(sstables::shared_sstable& a, sstables::shared_sstable& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(sstables::shared_sstable& a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}