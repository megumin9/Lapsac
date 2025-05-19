#include <bits/stdc++.h>
using namespace std;

struct OpDef {
    struct AttrDef {
        const string& name() const;
    };
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const OpDef::AttrDef* lhs, const OpDef::AttrDef* rhs) {
  return lhs->name() < rhs->name();
}

void test1(const OpDef::AttrDef* a, const OpDef::AttrDef* b, const OpDef::AttrDef* c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const OpDef::AttrDef* a, const OpDef::AttrDef* b, const OpDef::AttrDef* c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const OpDef::AttrDef* a, const OpDef::AttrDef* b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const OpDef::AttrDef* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}