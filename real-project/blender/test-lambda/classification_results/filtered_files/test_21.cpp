#include <bits/stdc++.h>
using namespace std;

struct Position {
    int y;
};

struct LinkAndPosition {
    Position multi_socket_position;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const LinkAndPosition a, const LinkAndPosition b) {
    return a.multi_socket_position.y < b.multi_socket_position.y;
}

void test1(LinkAndPosition a, LinkAndPosition b, LinkAndPosition c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(LinkAndPosition a, LinkAndPosition b, LinkAndPosition c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(LinkAndPosition a, LinkAndPosition b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(LinkAndPosition a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}