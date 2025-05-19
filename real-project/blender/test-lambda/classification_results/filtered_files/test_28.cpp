#include <bits/stdc++.h>
using namespace std;

struct ZoneOrNode {};
int get_zone_or_node_width(const ZoneOrNode&);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda4(const ZoneOrNode &a, const ZoneOrNode &b) {
    return get_zone_or_node_width(a) > get_zone_or_node_width(b);
}

void test1(ZoneOrNode a, ZoneOrNode b, ZoneOrNode c) {
    NewTest();
    if (!lambda4(a, b) && !lambda4(b, c) && lambda4(a, c)) {
        ConsistencyChecker();
    }
}

void test2(ZoneOrNode a, ZoneOrNode b, ZoneOrNode c) {
    NewTest();
    if (lambda4(a, b) && lambda4(b, c) && lambda4(c, a)) {
        TransiveChecker();
    }
}

void test3_1(ZoneOrNode a, ZoneOrNode b) {
    NewTest();
    if (lambda4(a, b) && lambda4(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(ZoneOrNode a, ZoneOrNode b) {
    NewTest();
    if (lambda4(a, b) && lambda4(b, a)) {
        SymmetryChecker();
    }
}

void test4(ZoneOrNode a) {
    NewTest();
    if (lambda4(a, a)) {
        ReflexivityChecker();
    }
}