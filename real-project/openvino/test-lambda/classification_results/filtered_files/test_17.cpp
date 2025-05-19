#include <bits/stdc++.h>
#include <vector>

namespace ov {
namespace npuw {
struct Group {
    std::vector<int> all_layers;
};
} // namespace npuw
} // namespace ov

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ov::npuw::Group& g1, const ov::npuw::Group& g2) {
    return g1.all_layers.front() < g2.all_layers.front();
}

void test1(const ov::npuw::Group& a, const ov::npuw::Group& b, const ov::npuw::Group& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const ov::npuw::Group& a, const ov::npuw::Group& b, const ov::npuw::Group& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const ov::npuw::Group& a, const ov::npuw::Group& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const ov::npuw::Group& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}