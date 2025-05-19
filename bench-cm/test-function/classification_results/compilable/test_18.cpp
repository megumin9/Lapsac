#include <string>

class Target {
public:
    const std::string& GetName() const;
};

class cmXCodeObject {
public:
    Target* GetTarget() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

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

void test1(cmXCodeObject* a, cmXCodeObject* b, cmXCodeObject* c) {
    NewTest();
    if (!compare_4(a,b) && !compare_4(b,c) && compare_4(a,c))
    ConsistencyChecker();
}

void test2(cmXCodeObject* a, cmXCodeObject* b, cmXCodeObject* c) {
    NewTest();
    if (compare_4(a,b) && compare_4(b,c) && compare_4(c,a))
    TransiveChecker();
}

void test3_1(cmXCodeObject* a, cmXCodeObject* b) {
    NewTest();
    if (compare_4(a,b) && compare_4(b,a))
    SymmetryChecker();
}

void test3_2(cmXCodeObject* a, cmXCodeObject* b) {
    NewTest();
    if (compare_4(a,b) && compare_4(b,a))
    SymmetryChecker();
}

void test4(cmXCodeObject* a) {
    NewTest();
    if (compare_4(a, a))
    ReflexivityChecker();
}