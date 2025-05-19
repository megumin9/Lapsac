#include <bits/stdc++.h>

struct Expr {
    int get_exec_num() const;
};

struct ExprPort {
    const Expr* get_expr() const;
    int get_index() const;
};

struct Port {
    const ExprPort& get_expr_port() const;
};

extern std::vector<Port> ports;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(size_t l, size_t r) {
    const ExprPort& expr_port_l = ports[l].get_expr_port();
    const ExprPort& expr_port_r = ports[r].get_expr_port();
    if (expr_port_l.get_expr() == expr_port_r.get_expr())
        return expr_port_l.get_index() < expr_port_r.get_index();
    return expr_port_l.get_expr()->get_exec_num() < expr_port_r.get_expr()->get_exec_num();
}

void test1(size_t a, size_t b, size_t c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(size_t a, size_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(size_t a, size_t b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(size_t a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}