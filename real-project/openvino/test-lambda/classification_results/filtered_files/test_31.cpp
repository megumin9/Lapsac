#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

namespace own { namespace ade {
struct NodeHandle {};
}}

namespace detail {
struct CreateIdx { int m_idx; };
}

class MyClass {
public:
    bool lambda3(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
        return this->meta(a).get<detail::CreateIdx>().m_idx < this->meta(b).get<detail::CreateIdx>().m_idx;
    }

    void test1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
        NewTest();
        if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c))
        ConsistencyChecker();
    }

    void test2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b, const own::ade::NodeHandle& c) {
        NewTest();
        if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a))
        TransiveChecker();
    }

    void test3_1(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
        NewTest();
        if (lambda3(a,b) && lambda3(b,a))
        SymmetryChecker();
    }

    void test3_2(const own::ade::NodeHandle& a, const own::ade::NodeHandle& b) {
        NewTest();
        if (lambda3(a,b) && lambda3(b,a))
        SymmetryChecker();
    }

    void test4(const own::ade::NodeHandle& a) {
        NewTest();
        if (lambda3(a, a))
        ReflexivityChecker();
    }

private:
    struct MetaType {
        template<typename T> const T& get() const;
    };
    MetaType meta(const own::ade::NodeHandle&) const { return MetaType(); }
};