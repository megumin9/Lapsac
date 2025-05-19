#include <bits/stdc++.h>
using namespace std;

struct NodeDef {
    const string& name() const;
};

extern unordered_map<const NodeDef*, int> recomputed_node_max_feed_components;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const NodeDef* first, const NodeDef* second) {
    int first_component = recomputed_node_max_feed_components.find(first)->second;
    int second_component = recomputed_node_max_feed_components.find(second)->second;
    return first_component > second_component || 
           (first_component == second_component && first->name() > second->name());
}

void test1(const NodeDef* a, const NodeDef* b, const NodeDef* c) {
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
        ConsistencyChecker();
}

void test2(const NodeDef* a, const NodeDef* b, const NodeDef* c) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(const NodeDef* a, const NodeDef* b) {
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(const NodeDef* a) {
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}