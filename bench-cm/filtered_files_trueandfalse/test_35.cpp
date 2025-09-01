#include <bits/stdc++.h>
using namespace std;

struct FragmentInfo {
    int OffsetInBits;
};

class ExprType {
public:
    FragmentInfo* getFragmentInfo() const;
};

struct GlobalExpr {
    ExprType* Expr;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_37(GlobalExpr A, GlobalExpr B) {
    if (A.Expr != B.Expr && A.Expr && B.Expr) {
        FragmentInfo* FragmentA = A.Expr->getFragmentInfo();
        FragmentInfo* FragmentB = B.Expr->getFragmentInfo();
        if (FragmentA && FragmentB)
            return FragmentA->OffsetInBits < FragmentB->OffsetInBits;
    }
    return false;
}

void test1(GlobalExpr a, GlobalExpr b, GlobalExpr c) {
    NewTest();
    if (!compare_37(a, b) && !compare_37(b, c) && compare_37(a, c))
        ConsistencyChecker();
}

void test2(GlobalExpr a, GlobalExpr b, GlobalExpr c) {
    NewTest();
    if (compare_37(a, b) && compare_37(b, c) && compare_37(c, a))
        TransiveChecker();
}

void test3_1(GlobalExpr a, GlobalExpr b) {
    NewTest();
    if (compare_37(a, b) && compare_37(b, a))
        SymmetryChecker();
}

void test3_2(GlobalExpr a, GlobalExpr b) {
    NewTest();
    if (compare_37(a, b) && compare_37(b, a))
        SymmetryChecker();
}

void test4(GlobalExpr a) {
    NewTest();
    if (compare_37(a, a))
        ReflexivityChecker();
}