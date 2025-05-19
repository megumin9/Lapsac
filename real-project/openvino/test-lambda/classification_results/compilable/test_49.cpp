#include <bits/stdc++.h>

namespace ov {
class Node;
}

extern std::map<std::shared_ptr<ov::Node>, int> index_map;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::shared_ptr<ov::Node>& a, const std::shared_ptr<ov::Node>& b) {
    return index_map[a] < index_map[b];
}

void test1(const std::shared_ptr<ov::Node>& a, const std::shared_ptr<ov::Node>& b, const std::shared_ptr<ov::Node>& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const std::shared_ptr<ov::Node>& a, const std::shared_ptr<ov::Node>& b, const std::shared_ptr<ov::Node>& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const std::shared_ptr<ov::Node>& a, const std::shared_ptr<ov::Node>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) 
        SymmetryChecker();
}

void test3_2(const std::shared_ptr<ov::Node>& a, const std::shared_ptr<ov::Node>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) 
        SymmetryChecker();
}

void test4(const std::shared_ptr<ov::Node>& a) {
    NewTest();
    if (lambda0(a, a)) 
        ReflexivityChecker();
}