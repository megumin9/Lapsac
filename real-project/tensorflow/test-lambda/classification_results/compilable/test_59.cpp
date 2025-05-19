#include <bits/stdc++.h>
#include <string_view>
#include <tuple>

enum class DataType { DT_RESOURCE };

struct Node {
    DataType output_type(int) const;
    std::string name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(Node* a, Node* b) {
    bool a_is_resource = (a->output_type(0) == DataType::DT_RESOURCE);
    bool b_is_resource = (b->output_type(0) == DataType::DT_RESOURCE);
    
    std::string_view a_name(a->name());
    std::string_view b_name(b->name());
    return std::tie(a_is_resource, a_name) < std::tie(b_is_resource, b_name);
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