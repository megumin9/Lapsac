#include <bits/stdc++.h>
using namespace std;

struct BoundBox {
    float min[3];
    float max[3];
};

class BVHReference {
public:
    int prim_object() const;
    int prim_index() const;
    int prim_type() const;
};

BoundBox get_prim_bounds(const BVHReference&);
int dim;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare(const BVHReference &ra, const BVHReference &rb) {
    BoundBox ra_bounds = get_prim_bounds(ra);
    BoundBox rb_bounds = get_prim_bounds(rb);
    const float ca = ra_bounds.min[dim] + ra_bounds.max[dim];
    const float cb = rb_bounds.min[dim] + rb_bounds.max[dim];

    if (ca < cb) return -1;
    if (ca > cb) return 1;
    if (ra.prim_object() < rb.prim_object()) return -1;
    if (ra.prim_object() > rb.prim_object()) return 1;
    if (ra.prim_index() < rb.prim_index()) return -1;
    if (ra.prim_index() > rb.prim_index()) return 1;
    if (ra.prim_type() < rb.prim_type()) return -1;
    if (ra.prim_type() > rb.prim_type()) return 1;
    return 0;
}

void test1(const BVHReference &a, const BVHReference &b, const BVHReference &c) {
    NewTest();
    if (!(compare(a,b)<0) && !(compare(b,c)<0) && (compare(a,c)<0))
        ConsistencyChecker();
}

void test2(const BVHReference &a, const BVHReference &b, const BVHReference &c) {
    NewTest();
    if ((compare(a,b)<0) && (compare(b,c)<0) && (compare(c,a)<0))
        TransiveChecker();
}

void test3_1(const BVHReference &a, const BVHReference &b) {
    NewTest();
    if ((compare(a,b)>0)&&(compare(b,a)>0))
        SymmetryChecker();
}

void test3_2(const BVHReference &a, const BVHReference &b) {
    NewTest();
    if ((compare(a,b)<0)&&(compare(b,a)<0))
        SymmetryChecker();
}

void test4(const BVHReference &a) {
    NewTest();
    if (compare(a,a)<0||compare(a,a)>0)
        ReflexivityChecker();
}