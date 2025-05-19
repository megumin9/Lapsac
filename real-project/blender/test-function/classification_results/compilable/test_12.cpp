#include <bits/stdc++.h>

enum { BM_ELEM_TAG = 1 };

struct BMVert;
struct BMEdge {
    BMVert* v1;
    BMVert* v2;
};

int BM_elem_flag_test(const BMVert* v, int flag);
float BM_edge_calc_length_squared(const BMEdge* e);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int bm_edge_length_cmp(const void *a_, const void *b_) {
  const BMEdge *e_a = static_cast<const BMEdge *>(*(const void **)a_);
  const BMEdge *e_b = static_cast<const BMEdge *>(*(const void **)b_);

  int e_a_concave = (BM_elem_flag_test(e_a->v1, BM_ELEM_TAG) &&
                     BM_elem_flag_test(e_a->v2, BM_ELEM_TAG));
  int e_b_concave = (BM_elem_flag_test(e_b->v1, BM_ELEM_TAG) &&
                     BM_elem_flag_test(e_b->v2, BM_ELEM_TAG));

  if (e_a_concave < e_b_concave) return -1;
  if (e_a_concave > e_b_concave) return 1;

  const float e_a_len = BM_edge_calc_length_squared(e_a);
  const float e_b_len = BM_edge_calc_length_squared(e_b);
  if (e_a_len < e_b_len) return 1;
  if (e_a_len > e_b_len) return -1;
  return 0;
}

void test1(const void* a, const void* b, const void* c) {
    NewTest();
    if (!(bm_edge_length_cmp(a,b)<0) && !(bm_edge_length_cmp(b,c)<0) && (bm_edge_length_cmp(a,c)<0))
        ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c) {
    NewTest();
    if ((bm_edge_length_cmp(a,b)<0) && (bm_edge_length_cmp(b,c)<0) && (bm_edge_length_cmp(c,a)<0))
        TransiveChecker();
}

void test3_1(const void* a, const void* b) {
    NewTest();
    if ((bm_edge_length_cmp(a,b)<0)&&(bm_edge_length_cmp(b,a)<0))
        SymmetryChecker();
}

void test3_2(const void* a, const void* b) {
    NewTest();
    if ((bm_edge_length_cmp(a,b)<0)&&(bm_edge_length_cmp(b,a)<0))
        SymmetryChecker();
}

void test4(const void* a) {
    NewTest();
    if (bm_edge_length_cmp(a, a)<0||bm_edge_length_cmp(a, a)>0)
        ReflexivityChecker();
}