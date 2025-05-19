#include <bits/stdc++.h>

struct EllipsoidDefinition {
    std::string description;
};

class Collator {
public:
    int compare(const std::string& a, const std::string& b) const;
};

Collator collator;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const EllipsoidDefinition & a, const EllipsoidDefinition & b) {
    return collator.compare( a.description, b.description ) < 0;
}

void test1(EllipsoidDefinition a, EllipsoidDefinition b, EllipsoidDefinition c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(EllipsoidDefinition a, EllipsoidDefinition b, EllipsoidDefinition c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(EllipsoidDefinition a, EllipsoidDefinition b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(EllipsoidDefinition a, EllipsoidDefinition b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(EllipsoidDefinition a) {
    NewTest();
    if (lambda0(a,a))
        ReflexivityChecker();
}