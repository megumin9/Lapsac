#include <bits/stdc++.h>
using namespace std;

struct StringCmp {
    char *name;
};

int BLI_strcasecmp(const char *s1, const char *s2);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int cmpstringp(const void *p1, const void *p2) {
    return BLI_strcasecmp(((StringCmp *)p1)->name, ((StringCmp *)p2)->name);
}

void test1(StringCmp *a, StringCmp *b, StringCmp *c) {
    NewTest();
    if (!(cmpstringp(a,b)<0) && !(cmpstringp(b,c)<0) && (cmpstringp(a,c)<0))
        ConsistencyChecker();
}

void test2(StringCmp *a, StringCmp *b, StringCmp *c) {
    NewTest();
    if ((cmpstringp(a,b)<0) && (cmpstringp(b,c)<0) && (cmpstringp(c,a)<0))
        TransiveChecker();
}

void test3_2(StringCmp *a, StringCmp *b) {
    NewTest();
    if ((cmpstringp(a,b)<0)&&(cmpstringp(b,a)<0))
        SymmetryChecker();
}

void test4(StringCmp *a) {
    NewTest();
    if (cmpstringp(a, a)<0 || cmpstringp(a, a)>0)
        ReflexivityChecker();
}