#include <bits/stdc++.h>

struct layout {
    size_t bytes_count() const;
};

struct program_node {
    layout get_output_layout() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(program_node* const& lhs, program_node* const& rhs) {
    return (lhs->get_output_layout().bytes_count() > rhs->get_output_layout().bytes_count());
}

void test1(program_node* a, program_node* b, program_node* c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(program_node* a, program_node* b, program_node* c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(program_node* a, program_node* b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(program_node* a, program_node* b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(program_node* a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}