#include <bits/stdc++.h>

struct map_pair {
    struct Key {
        int serialize_nonnull() const;
    } first;
};

struct Comparator {
    bool less(int, int) const;
};

Comparator* key_type;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const map_pair& a, const map_pair& b) {
    return key_type->less(a.first.serialize_nonnull(), b.first.serialize_nonnull());
}

void test1(const map_pair& a, const map_pair& b, const map_pair& c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const map_pair& a, const map_pair& b, const map_pair& c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const map_pair& a, const map_pair& b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const map_pair& a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}