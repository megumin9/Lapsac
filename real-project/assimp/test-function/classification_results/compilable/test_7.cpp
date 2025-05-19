#include <bits/stdc++.h>

struct m3dl_t {
    const char* lang;
    const char* name;
    const char* text;
};

int _m3d_strcmp(const char*, const char*);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int _m3d_lblcmp(const void *a, const void *b) {
    const m3dl_t *A = (const m3dl_t *)a, *B = (const m3dl_t *)b;
    int c = _m3d_strcmp(A->lang, B->lang);
    if (!c) c = _m3d_strcmp(A->name, B->name);
    if (!c) c = _m3d_strcmp(A->text, B->text);
    return c;
}

void test1(void *a, void *b, void *c) {
    NewTest();
    if (!(_m3d_lblcmp(a,b)<0) && !(_m3d_lblcmp(b,c)<0) && (_m3d_lblcmp(a,c)<0))
        ConsistencyChecker();
}

void test2(void *a, void *b, void *c) {
    NewTest();
    if ((_m3d_lblcmp(a,b)<0) && (_m3d_lblcmp(b,c)<0) && (_m3d_lblcmp(c,a)<0))
        TransiveChecker();
}

void test3_1(void *a, void *b) {
    NewTest();
    if ((_m3d_lblcmp(a,b)>0)&&(_m3d_lblcmp(b,a)>0))
        SymmetryChecker();
}

void test3_2(void *a, void *b) {
    NewTest();
    if ((_m3d_lblcmp(a,b)<0)&&(_m3d_lblcmp(b,a)<0))
        SymmetryChecker();
}

void test4(void *a) {
    NewTest();
    if (_m3d_lblcmp(a, a)<0||_m3d_lblcmp(a, a)>0)
        ReflexivityChecker();
}