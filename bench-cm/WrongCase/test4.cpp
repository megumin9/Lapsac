// https://github.com/Kitware/CMake/commit/80d0770250182bd3705c226312b0e2a9e86a3495

// Violation of Anti-Reflexivity

bool compare_4(cmXCodeObject* l, cmXCodeObject* r) {
    std::string const& a = l->GetTarget()->GetName();
    std::string const& b = r->GetTarget()->GetName();

    if (a == "ALL_BUILD") {
        return true;
    }

    if (b == "ALL_BUILD") {
        return false;
    }

    return a < b;
}