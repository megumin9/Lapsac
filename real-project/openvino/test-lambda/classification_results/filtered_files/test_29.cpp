#include <bits/stdc++.h>

namespace own { namespace ade { struct NodeHandle {}; } }
namespace detail { struct CreateIdx { int m_idx; }; }

class Graph;
struct MetaData {
    template<typename T> T get() const;
};
class Graph {
public:
    MetaData meta(const own::ade::NodeHandle&) const;
};

extern std::weak_ptr<Graph> m_graph;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
    auto locked_graph = m_graph.lock();
    return locked_graph->meta(a).get<detail::CreateIdx>().m_idx <
           locked_graph->meta(b).get<detail::CreateIdx>().m_idx;
}

void test1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
        ConsistencyChecker();
}

void test2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(const own::ade::NodeHandle& a) {
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}