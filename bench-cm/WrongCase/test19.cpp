// https://github.com/facebook/redex/commit/b58f74d68b41d27e419539074a2f5a6d85adbc1d

// Violation of Anti-Symmetry 

bool compare_19(const std::string& a, const std::string& b) {
    if (a == "COLD_START" && b != "COLD_START") {
        return true;
    }
    if (a == b) {
        return false;
    }

    return a < b;
}