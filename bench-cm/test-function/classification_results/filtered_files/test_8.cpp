
#include <bits/stdc++.h>

class Network {
public:
    int prefix_length() const;
    std::string name() const;
    int prefix() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_18(const std::unique_ptr<Network>& a, const std::unique_ptr<Network>& b) {
    if (a->prefix_length() == b->prefix_length()) {
        if (a->name() == b->name()) {
            return a->prefix() < b->prefix();
        }
    }
    return a->name() < b->name();
}

void test1(const std::unique_ptr<Network>& a, const std::unique_ptr<Network>& b, const std::unique_ptr<Network>& c) {
    NewTest();
    if (!compare_18(a,b) && !compare_18(b,c) && compare_18(a,c)) 
        ConsistencyChecker();
}

void test2(const std::unique_ptr<Network>& a, const std::unique_ptr<Network>& b, const std::unique_ptr<Network>& c) {
    NewTest();
    if (compare_18(a,b) && compare_18(b,c) && compare_18(c,a)) 
        TransiveChecker();
}

void test3_1(const std::unique_ptr<Network>& a, const std::unique_ptr<Network>& b) {
    NewTest();
    if (compare_18(a,b) && compare_18(b,a))
        SymmetryChecker();
}

void test3_2(const std::unique_ptr<Network>& a, const std::unique_ptr<Network>& b) {
    NewTest();
    if (compare_18(a,b) && compare_18(b,a))
        SymmetryChecker();
}

void test4(const std::unique_ptr<Network>& a) {
    NewTest();
    if (compare_18(a, a)) 
        ReflexivityChecker();
}
