#include <bits/stdc++.h>
#include <cstring>

struct m3dti_t {};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int _m3d_ticmp(const void *a, const void *b) {
    return memcmp(a, b, sizeof(m3dti_t));
}

void test1(const void* a, const void* b, const void* c){
    NewTest();
    if (!(_m3d_ticmp(a,b)<0) && !(_m3d_ticmp(b,c)<0) && (_m3d_ticmp(a,c)<0))
    ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
    NewTest();
    if ((_m3d_ticmp(a,b)<0) && (_m3d_ticmp(b,c)<0) && (_m3d_ticmp(c,a)<0))
    TransiveChecker();
}

void test3_1(const void* a, const void* b){
    NewTest();
    if ((_m3d_ticmp(a,b)>0)&&(_m3d_ticmp(b,a)>0))
    SymmetryChecker();
}

void test3_2(const void* a, const void* b){
    NewTest();
    if ((_m3d_ticmp(a,b)<0)&&(_m3d_ticmp(b,a)<0))
    SymmetryChecker();
}

void test4(const void* a){
    NewTest();
    if (_m3d_ticmp(a, a)<0 || _m3d_ticmp(a, a)>0) 
    ReflexivityChecker();
}