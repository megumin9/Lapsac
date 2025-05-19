#include <cstring>

struct m3ds_t { int dummy; };

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int _m3d_skincmp(const void *a, const void *b) {
    return memcmp(a, b, sizeof(m3ds_t));
}

void test1(void* a, void* b, void* c){
    NewTest();
    if (!(_m3d_skincmp(a,b)<0) && !(_m3d_skincmp(b,c)<0) && (_m3d_skincmp(a,c)<0))
    ConsistencyChecker();
}

void test2(void* a, void* b, void* c){
    NewTest();
    if ((_m3d_skincmp(a,b)<0) && (_m3d_skincmp(b,c)<0) && (_m3d_skincmp(c,a)<0))
    TransiveChecker();
}

void test3_2(void* a, void* b){
    NewTest();
    if ((_m3d_skincmp(a,b)<0)&&(_m3d_skincmp(b,a)<0))
    SymmetryChecker();
}

void test4(void* a){
    NewTest();
    if (_m3d_skincmp(a, a)<0||_m3d_skincmp(a, a)>0) 
    ReflexivityChecker();
}