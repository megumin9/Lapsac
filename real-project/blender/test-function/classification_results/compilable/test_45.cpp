#include <bits/stdc++.h>

struct OrderEdge {
    int verts[2];
    int e_half;
};

void BLI_assert(bool);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int oedge_cmp(const void *a1, const void *a2) {
  const OrderEdge *x1 = static_cast<const OrderEdge *>(a1);
  const OrderEdge *x2 = static_cast<const OrderEdge *>(a2);
  if (x1->verts[0] > x2->verts[0]) {
    return 1;
  }
  if (x1->verts[0] < x2->verts[0]) {
    return -1;
  }

  if (x1->verts[1] > x2->verts[1]) {
    return 1;
  }
  if (x1->verts[1] < x2->verts[1]) {
    return -1;
  }

  
  if (x1->e_half > x2->e_half) {
    return 1;
  }
  if (x1->e_half < x2->e_half) {
    return -1;
  }
  
  BLI_assert(false);
  return 0;
}

void test1(const void* a, const void* b, const void* c){
    NewTest();
    if (!(oedge_cmp(a,b) < 0) && !(oedge_cmp(b,c) < 0) && (oedge_cmp(a,c) < 0))
        ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
    NewTest();
    if ((oedge_cmp(a,b) < 0) && (oedge_cmp(b,c) < 0) && (oedge_cmp(c,a) < 0))
        TransiveChecker();
}

void test3_1(const void* a, const void* b){
    NewTest();
    if ((oedge_cmp(a,b) > 0) && (oedge_cmp(b,a) > 0))
        SymmetryChecker();
}

void test3_2(const void* a, const void* b){
    NewTest();
    if ((oedge_cmp(a,b) < 0) && (oedge_cmp(b,a) < 0))
        SymmetryChecker();
}

void test4(const void* a){
    NewTest();
    if (oedge_cmp(a, a) < 0 || oedge_cmp(a, a) > 0)
        ReflexivityChecker();
}