#include <bits/stdc++.h>

namespace own { namespace ade { struct NodeHandle; } }
struct Group;
struct Graph;
struct MetaData;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct Group {
    using GPtr = Group*;
    int size() const;
};

namespace own { namespace ade { struct NodeHandle {}; } }
struct MetaData {
    template<typename T> T get();
};
struct Graph {
    MetaData meta(const own::ade::NodeHandle& nh) const;
};
extern Graph* m_graph;

bool lambda0(const own::ade::NodeHandle& nh1, const own::ade::NodeHandle& nh2) {
    Group::GPtr g1 = m_graph->meta(nh1).get<Group::GPtr>();
    Group::GPtr g2 = m_graph->meta(nh2).get<Group::GPtr>();
    return g1->size() < g2->size();
}

void test1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const own::ade::NodeHandle& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}