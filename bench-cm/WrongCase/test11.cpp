//https://github.com/facebook/hhvm/commit/0343b23155206a0b567bb4f2d72e4d8db26dadf7

// Violation of Anti-Reflexivity

bool compare_11(const Entry& a, const Entry& b) {
    if (b.funcId == InvalidFuncId) return true;
    return a.count >= b.count;
}
