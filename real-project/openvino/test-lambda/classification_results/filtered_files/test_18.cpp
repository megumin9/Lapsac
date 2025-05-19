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

bool lambda1(const ov::npuw::Group& g1, const ov::npuw::Group& g2) {
    return g1.all_layers.front() < g2.all_layers.front();
}

void test1(ov::npuw::Group a, ov::npuw::Group b, ov::npuw::Group c) {
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(ov::npuw::Group a, ov::npuw::Group b, ov::npuw::Group c) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(ov::npuw::Group a, ov::npuw::Group b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(ov::npuw::Group a, ov::npuw::Group b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(ov::npuw::Group a) {
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}