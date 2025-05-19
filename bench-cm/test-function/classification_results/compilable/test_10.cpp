#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct peer_connection {
    bool is_connecting() const;
    bool is_disconnecting() const;
    int connected_time() const;
};

bool compare_20(peer_connection const* lhs, peer_connection const* rhs) {
    bool lhs_connecting = lhs->is_connecting() && !lhs->is_disconnecting();
    bool rhs_connecting = rhs->is_connecting() && !rhs->is_disconnecting();

    if (lhs_connecting > rhs_connecting) return false;
    if (lhs_connecting < rhs_connecting) return true;

    return lhs->connected_time() >= rhs->connected_time();
}

void test1(peer_connection const* a, peer_connection const* b, peer_connection const* c) {
    NewTest();
    if (!compare_20(a,b) && !compare_20(b,c) && compare_20(a,c)) 
        ConsistencyChecker();
}

void test2(peer_connection const* a, peer_connection const* b, peer_connection const* c) {
    NewTest();
    if (compare_20(a,b) && compare_20(b,c) && compare_20(c,a)) 
        TransiveChecker();
}

void test3_1(peer_connection const* a, peer_connection const* b) {
    NewTest();
    if (compare_20(a,b) && compare_20(b,a))
        SymmetryChecker();
}

void test3_2(peer_connection const* a, peer_connection const* b) {
    NewTest();
    if (compare_20(a,b) && compare_20(b,a))
        SymmetryChecker();
}

void test4(peer_connection const* a) {
    NewTest();
    if (compare_20(a, a)) 
        ReflexivityChecker();
}