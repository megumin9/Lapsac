#include <bits/stdc++.h>

class tensor {};
class layout {
public:
    bool is_dynamic() const;
    bool has_upper_bound() const;
    void set_tensor(const tensor&);
    tensor get_tensor() const;
    size_t bytes_count() const;
};
class program_node {
public:
    layout get_output_layout() const;
};
class processing_order {
public:
    int get_processing_number(program_node* node) const;
};
extern processing_order po;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(std::shared_ptr<program_node> const& lhs, std::shared_ptr<program_node> const& rhs) {
    layout lhs_layout = lhs->get_output_layout();
    layout rhs_layout = rhs->get_output_layout();
    if (lhs_layout.is_dynamic() && lhs_layout.has_upper_bound()) {
        lhs_layout.set_tensor(lhs_layout.get_tensor());
    }
    if (rhs_layout.is_dynamic() && rhs_layout.has_upper_bound()) {
        rhs_layout.set_tensor(rhs_layout.get_tensor());
    }

    if (rhs_layout.is_dynamic() && !rhs_layout.has_upper_bound() && lhs_layout.is_dynamic() && !lhs_layout.has_upper_bound()) {
        return po.get_processing_number(lhs.get()) < po.get_processing_number(rhs.get());
    }

    if (rhs_layout.is_dynamic())
        return true;
    if (lhs_layout.is_dynamic())
        return false;

    return (lhs_layout.bytes_count() > rhs_layout.bytes_count());
}

void test1(std::shared_ptr<program_node> const& a, std::shared_ptr<program_node> const& b, std::shared_ptr<program_node> const& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(std::shared_ptr<program_node> const& a, std::shared_ptr<program_node> const& b, std::shared_ptr<program_node> const& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(std::shared_ptr<program_node> const& a, std::shared_ptr<program_node> const& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(std::shared_ptr<program_node> const& a, std::shared_ptr<program_node> const& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(std::shared_ptr<program_node> const& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}