#include <bits/stdc++.h>
struct NewCollision {
    int first;
    int second;
    int colldata;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_14(const NewCollision &a, const NewCollision &b) {
    if (a.first == b.first) {
        if (a.second == b.second) {
            return a.colldata < b.colldata;
        }
        return a.second < b.second;
    }
    return a.first < b.first;
}

void test1(const NewCollision &a, const NewCollision &b, const NewCollision &c) {
    NewTest();
    if (!compare_14(a,b) && !compare_14(b,c) && compare_14(a,c))
        ConsistencyChecker();
}

void test2(const NewCollision &a, const NewCollision &b, const NewCollision &c) {
    NewTest();
    if (compare_14(a,b) && compare_14(b,c) && compare_14(c,a))
        TransiveChecker();
}

void test3_1(const NewCollision &a, const NewCollision &b) {
    NewTest();
    if (compare_14(a,b) && compare_14(b,a))
        SymmetryChecker();
}

void test3_2(const NewCollision &a, const NewCollision &b) {
    NewTest();
    if (compare_14(a,b) && compare_14(b,a))
        SymmetryChecker();
}

void test4(const NewCollision &a) {
    NewTest();
    if (compare_14(a, a))
        ReflexivityChecker();
}