#include <bits/stdc++.h>

namespace App {
struct DocumentObject {
    template<typename T>
    bool isDerivedFrom() const;
};
}

struct FemPostFilter;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const App::DocumentObject* lhs, const App::DocumentObject* rhs) {
    int l = lhs->isDerivedFrom<FemPostFilter>() ? 0 : 1;
    int r = rhs->isDerivedFrom<FemPostFilter>() ? 0 : 1;
    return r < l;
}

void test1(const App::DocumentObject* a, const App::DocumentObject* b, const App::DocumentObject* c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const App::DocumentObject* a, const App::DocumentObject* b, const App::DocumentObject* c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const App::DocumentObject* a, const App::DocumentObject* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(const App::DocumentObject* a, const App::DocumentObject* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const App::DocumentObject* a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}