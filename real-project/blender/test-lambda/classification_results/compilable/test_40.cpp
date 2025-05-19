#include <bits/stdc++.h>

struct InstanceListEntry {
    const char* name;
};

extern int BLI_strcasecmp_natural(const char*, const char*);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const InstanceListEntry &a, const InstanceListEntry &b) {
  return BLI_strcasecmp_natural(a.name, b.name) < 0;
}

void test1(InstanceListEntry a, InstanceListEntry b, InstanceListEntry c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(InstanceListEntry a, InstanceListEntry b, InstanceListEntry c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(InstanceListEntry a, InstanceListEntry b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(InstanceListEntry a, InstanceListEntry b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(InstanceListEntry a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}