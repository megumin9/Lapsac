#include <bits/stdc++.h>
struct FragmentInfo {
    int OffsetInBits;
};
struct ExprType {
    FragmentInfo* getFragmentInfo();
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
  if (!A.Expr || !B.Expr)
    return !!B.Expr;
  FragmentInfo* FragmentA = A.Expr->getFragmentInfo();
  FragmentInfo* FragmentB = B.Expr->getFragmentInfo();
  if (!FragmentA || !FragmentB)
    return !!FragmentB;
  return FragmentA->OffsetInBits < FragmentB->OffsetInBits;
}

void test1(GlobalExpr a, GlobalExpr b, GlobalExpr c){
NewTest();
if (!compare_37(a,b) && !compare_37(b,c) && compare_37(a,c)) 
ConsistencyChecker();
}

void test2(GlobalExpr a, GlobalExpr b, GlobalExpr c){
NewTest();
if (compare_37(a,b) && compare_37(b,c) && compare_37(c,a)) 
TransiveChecker();
}

void test3_1(GlobalExpr a, GlobalExpr b){
NewTest();
if (compare_37(a,b) && compare_37(b,a)) 
SymmetryChecker();
}

void test3_2(GlobalExpr a, GlobalExpr b){
NewTest();
if (compare_37(a,b) && compare_37(b,a)) 
SymmetryChecker();
}

void test4(GlobalExpr a){
NewTest();
if (compare_37(a, a)) 
ReflexivityChecker();
}