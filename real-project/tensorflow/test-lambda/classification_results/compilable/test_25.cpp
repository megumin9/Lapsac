#include <bits/stdc++.h>

enum DataType {
    DT_RESOURCE
};

class Node {
public:
    std::string name() const;
    DataType output_type(int) const;
};

bool is_guaranteed_constant(const Node&);
bool is_replicated_input(const Node&, bool*);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(Node* a, Node* b) {
    bool a_is_guaranteed_constant = is_guaranteed_constant(*a);
    bool b_is_guaranteed_constant = is_guaranteed_constant(*b);
    
    bool a_is_packed;
    bool b_is_packed;
    
    bool a_not_replicated = !is_replicated_input(*a, &a_is_packed);
    bool b_not_replicated = !is_replicated_input(*b, &b_is_packed);
    
    bool a_is_resource = (a->output_type(0) == DT_RESOURCE);
    bool b_is_resource = (b->output_type(0) == DT_RESOURCE);
    
    std::string_view a_name(a->name());
    std::string_view b_name(b->name());
    return std::tie(a_is_guaranteed_constant, a_not_replicated, a_is_packed,
                    a_is_resource, a_name) <
           std::tie(b_is_guaranteed_constant, b_not_replicated, b_is_packed,
                    b_is_resource, b_name);
}

void test1(Node* a, Node* b, Node* c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(Node* a, Node* b, Node* c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(Node* a, Node* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(Node* a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}