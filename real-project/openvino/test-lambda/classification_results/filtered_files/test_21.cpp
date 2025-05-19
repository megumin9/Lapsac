#include <utility>
#include <string>

struct Node {
    std::string get_friendly_name() const;
};

using PairNodePtr = std::pair<Node*, Node*>;

void NPUW_ASSERT(bool);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const PairNodePtr& p1, const PairNodePtr& p2) {
    NPUW_ASSERT(p1.first->get_friendly_name() != p2.first->get_friendly_name());
    return p1.first->get_friendly_name() < p2.first->get_friendly_name();
}

void test1(const PairNodePtr& a, const PairNodePtr& b, const PairNodePtr& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const PairNodePtr& a, const PairNodePtr& b, const PairNodePtr& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const PairNodePtr& a, const PairNodePtr& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const PairNodePtr& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}