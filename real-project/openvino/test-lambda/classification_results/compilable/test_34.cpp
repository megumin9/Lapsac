#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

namespace cldnn { struct program_node; }

bool lambda0(const std::pair<cldnn::program_node*, unsigned int>& a, const std::pair<cldnn::program_node*, unsigned int>& b) {
    return a.second < b.second;
}

void test1(const std::pair<cldnn::program_node*, unsigned int>& a, const std::pair<cldnn::program_node*, unsigned int>& b, const std::pair<cldnn::program_node*, unsigned int>& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const std::pair<cldnn::program_node*, unsigned int>& a, const std::pair<cldnn::program_node*, unsigned int>& b, const std::pair<cldnn::program_node*, unsigned int>& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const std::pair<cldnn::program_node*, unsigned int>& a, const std::pair<cldnn::program_node*, unsigned int>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const std::pair<cldnn::program_node*, unsigned int>& a, const std::pair<cldnn::program_node*, unsigned int>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const std::pair<cldnn::program_node*, unsigned int>& a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}