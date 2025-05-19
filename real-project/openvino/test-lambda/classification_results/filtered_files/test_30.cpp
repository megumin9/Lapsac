#include <bits/stdc++.h>

namespace own { namespace ade { struct NodeHandle {}; } }
namespace detail { struct CreateIdx { int m_idx; }; }

class Checker {
    template<typename T> struct MetaType {
        const T& get() const { static T obj; return obj; }
    };

public:
    bool lambda2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
        return meta<detail::CreateIdx>(a).get().m_idx < meta<detail::CreateIdx>(b).get().m_idx;
    }

    void test1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
        NewTest();
        if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
        ConsistencyChecker();
    }

    void test2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
        NewTest();
        if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
        TransiveChecker();
    }

    void test3_1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
        NewTest();
        if (lambda2(a,b) && lambda2(b,a))
        SymmetryChecker();
    }

    void test3_2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
        NewTest();
        if (lambda2(a,b) && lambda2(b,a))
        SymmetryChecker();
    }

    void test4(const own::ade::NodeHandle& a) {
        NewTest();
        if (lambda2(a, a))
        ReflexivityChecker();
    }

private:
    template<typename T> MetaType<T> meta(const own::ade::NodeHandle&) const { return {}; }
    void NewTest() {}
    void ConsistencyChecker() {}
    void TransiveChecker() {}
    void SymmetryChecker() {}
    void ReflexivityChecker() {}
};