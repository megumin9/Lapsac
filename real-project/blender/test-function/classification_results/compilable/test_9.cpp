
#include <bits/stdc++.h>
using namespace std;

struct BMFace {
    int len;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int bm_face_len_cmp(const void *v1, const void *v2) {
  const BMFace *f1 = *((BMFace **)v1);
  const BMFace *f2 = *((BMFace **)v2);

  if (f1->len > f2->len) {
    return 1;
  }
  if (f1->len < f2->len) {
    return -1;
  }
  return 0;
}

void test1(BMFace *a, BMFace *b, BMFace *c) {
  NewTest();
  if (!(bm_face_len_cmp(a,b)<0) && !(bm_face_len_cmp(b,c)<0) && (bm_face_len_cmp(a,c)<0)) 
    ConsistencyChecker();
}

void test2(BMFace *a, BMFace *b, BMFace *c) {
  NewTest();
  if ((bm_face_len_cmp(a,b)<0) && (bm_face_len_cmp(b,c)<0) && (bm_face_len_cmp(c,a)<0)) 
    TransiveChecker();
}

void test3_1(BMFace *a, BMFace *b) {
  NewTest();
  if ((bm_face_len_cmp(a,b)>0)&&(bm_face_len_cmp(b,a)>0))
    SymmetryChecker();
}

void test3_2(BMFace *a, BMFace *b) {
  NewTest();
  if ((bm_face_len_cmp(a,b)<0)&&(bm_face_len_cmp(b,a)<0))
    SymmetryChecker();
}

void test4(BMFace *a) {
  NewTest();
  if (bm_face_len_cmp(a,a)<0||bm_face_len_cmp(a,a)>0) 
    ReflexivityChecker();
}
