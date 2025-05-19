#include <cstdint>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int _m3d_grpcmp(const void *a, const void *b) {
    return *((const uint32_t *)a) - *((const uint32_t *)b);
}

void test1(const void* a, const void* b, const void* c) {
    NewTest();
    if (!(_m3d_grpcmp(a,b)<0) && !(_m3d_grpcmp(b,c)<0) && (_m3d_grpcmp(a,c)<0)) 
        ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c) {
    NewTest();
    if ((_m3d_grpcmp(a,b)<0) && (_m3d_grpcmp(b,c)<0) && (_m3d_grpcmp(c,a)<0)) 
        TransiveChecker();
}

void test3_1(const void* a, const void* b) {
    NewTest();
    if ((_m3d_grpcmp(a,b)>0)&&(_m3d_grpcmp(b,a)>0))
        SymmetryChecker();
}

void test3_2(const void* a, const void* b) {
    NewTest();
    if ((_m3d_grpcmp(a,b)<0)&&(_m3d_grpcmp(b,a)<0))
        SymmetryChecker();
}

void test4(const void* a) {
    NewTest();
    if (_m3d_grpcmp(a, a)<0||_m3d_grpcmp(a, a)>0) 
        ReflexivityChecker();
}