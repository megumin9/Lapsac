#include <bits/stdc++.h>
using namespace std;

class Mesh {
public:
    int device_type() const;
    bool operator<(const Mesh& other) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Mesh& a, const Mesh& b) {
    if (a.device_type() != b.device_type()) {
        return a.device_type() < b.device_type();
    }
    return a < b;
}

void test1(const Mesh& a, const Mesh& b, const Mesh& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const Mesh& a, const Mesh& b, const Mesh& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const Mesh& a, const Mesh& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const Mesh& a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}