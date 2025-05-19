#include <bits/stdc++.h>

struct decorated_gid {
    int key;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();
bool less(int a, int b);

bool lambda0(const decorated_gid& l, const decorated_gid& r) {
    return less(l.key, r.key);
}

void test1(decorated_gid a, decorated_gid b, decorated_gid c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(decorated_gid a, decorated_gid b, decorated_gid c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(decorated_gid a, decorated_gid b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(decorated_gid a, decorated_gid b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(decorated_gid a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}