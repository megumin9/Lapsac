
#include <cstring>

typedef int M3D_FLOAT;

struct m3dvsave_t {
    M3D_FLOAT coords[3];
    int norm;
};

struct m3dv_t {
    m3dvsave_t save;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int _m3d_vrtxcmp(const void *a, const void *b) {
    int c = memcmp(a, b, 3 * sizeof(M3D_FLOAT));
    if (c) return c;
    c = ((m3dvsave_t *)a)->norm - ((m3dvsave_t *)b)->norm;
    if (c) return c;
    return memcmp(a, b, sizeof(m3dv_t));
}

void test1(m3dv_t* a, m3dv_t* b, m3dv_t* c) {
    NewTest();
    if (!(_m3d_vrtxcmp(a,b)<0) && !(_m3d_vrtxcmp(b,c)<0) && (_m3d_vrtxcmp(a,c)<0))
        ConsistencyChecker();
}

void test2(m3dv_t* a, m3dv_t* b, m3dv_t* c) {
    NewTest();
    if ((_m3d_vrtxcmp(a,b)<0) && (_m3d_vrtxcmp(b,c)<0) && (_m3d_vrtxcmp(c,a)<0))
        TransiveChecker();
}

void test3_1(m3dv_t* a, m3dv_t* b) {
    NewTest();
    if ((_m3d_vrtxcmp(a,b)>0)&&(_m3d_vrtxcmp(b,a)>0))
        SymmetryChecker();
}

void test3_2(m3dv_t* a, m3dv_t* b) {
    NewTest();
    if ((_m3d_vrtxcmp(a,b)<0)&&(_m3d_vrtxcmp(b,a)<0))
        SymmetryChecker();
}

void test4(m3dv_t* a) {
    NewTest();
    if (_m3d_vrtxcmp(a, a)<0||_m3d_vrtxcmp(a, a)>0) 
        ReflexivityChecker();
}
