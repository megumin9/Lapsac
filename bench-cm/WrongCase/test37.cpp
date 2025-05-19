// https://github.com/DeNA/DeClang/commit/48e7549691d7dbe3be1a78f7419953fb48181678

// Violation of Consistency

bool compare_37(GlobalExpr A, GlobalExpr B) {
    if (A.Expr != B.Expr && A.Expr && B.Expr) {
        auto FragmentA = A.Expr->getFragmentInfo();
        auto FragmentB = B.Expr->getFragmentInfo();
        if (FragmentA && FragmentB)
            return FragmentA->OffsetInBits < FragmentB->OffsetInBits;
    }
    return false;
}