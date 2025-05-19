#include <bits/stdc++.h>

struct m3dfsave_t {
    int group;
    int opacity;
    struct { int materialid; } data;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int _m3d_facecmp(const void *a, const void *b) {
    const m3dfsave_t *A = (const m3dfsave_t *)a, *B = (const m3dfsave_t *)b;
    return A->group != B->group ? A->group - B->group : (A->opacity != B->opacity ? (int)B->opacity - (int)A->opacity : (int)A->data.materialid - (int)B->data.materialid);
}

void test1(const void *a, const void *b, const void *c) {
    NewTest();
    if (!(_m3d_facecmp(a,b)<0) && ! (_m3d_facecmp(b,c)<0) && (_m3d_facecmp(a,c)<0))
        ConsistencyChecker();
}

void test2(const void *a, const void *b, const void *c) {
    NewTest();
    if ((_m3d_facecmp(a,b)<0) && (_m3d_facecmp(b,c)<0) && (_m3d_facecmp(c,a)<0)) 
        TransiveChecker();
}

void test3_1(const void *a, const void *b) {
    NewTest();
    if ((_m3d_facecmp(a,b)>0)&&(_m3d_facecmp(b,a)>0))
        SymmetryChecker();
}

void test3_2(const void *a, const void *b) {
    NewTest();
    if ((_m3d_facecmp(a,b)<0)&&(_m3d_facecmp(b,a)<0))
        SymmetryChecker();
}

void test4(const void *a) {
    NewTest();
    if (_m3d_facecmp(a, a)<0||_m3d_facecmp(a, a)>0) 
        ReflexivityChecker();
}