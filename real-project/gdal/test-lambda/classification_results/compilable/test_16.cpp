
#include <bits/stdc++.h>
using namespace std;

struct BatchItem {
    int featureIdx;
};

struct FeatureItem {
    int offset;
};

vector<FeatureItem> m_featureItems;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const BatchItem &a, const BatchItem &b) {
    return m_featureItems[a.featureIdx].offset < m_featureItems[b.featureIdx].offset;
}

void test1(BatchItem a, BatchItem b, BatchItem c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(BatchItem a, BatchItem b, BatchItem c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(BatchItem a, BatchItem b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(BatchItem a, BatchItem b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(BatchItem a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}
