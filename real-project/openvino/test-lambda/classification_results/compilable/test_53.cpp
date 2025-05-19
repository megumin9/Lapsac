#include <bits/stdc++.h>
using namespace std;

struct BufferExpression {
    int get_exec_num() const;
};
using BufferExpressionPtr = shared_ptr<BufferExpression>;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const BufferExpressionPtr& lhs, const BufferExpressionPtr& rhs) {
    return lhs->get_exec_num() < rhs->get_exec_num();
}

void test1(const BufferExpressionPtr& a, const BufferExpressionPtr& b, const BufferExpressionPtr& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const BufferExpressionPtr& a, const BufferExpressionPtr& b, const BufferExpressionPtr& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const BufferExpressionPtr& a, const BufferExpressionPtr& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const BufferExpressionPtr& a, const BufferExpressionPtr& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const BufferExpressionPtr& a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}