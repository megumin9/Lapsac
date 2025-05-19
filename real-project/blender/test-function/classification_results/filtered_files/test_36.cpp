#include <bits/stdc++.h>

int smart_uv_project_area_ignore;

struct ThickFace {
    int area;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int smart_uv_project_thickface_area_cmp_fn(const void *tf_a_p, const void *tf_b_p) {
  const ThickFace *tf_a = (ThickFace *)tf_a_p;
  const ThickFace *tf_b = (ThickFace *)tf_b_p;

  if (!((tf_a->area > smart_uv_project_area_ignore) ||
        (tf_b->area > smart_uv_project_area_ignore)))
  {
    return 0;
  }

  if (tf_a->area < tf_b->area) {
    return 1;
  }
  if (tf_a->area > tf_b->area) {
    return -1;
  }
  return 0;
}

void test1(ThickFace* a, ThickFace* b, ThickFace* c){
  NewTest();
  if (!(smart_uv_project_thickface_area_cmp_fn(a,b) < 0) && 
      !(smart_uv_project_thickface_area_cmp_fn(b,c) < 0) && 
      (smart_uv_project_thickface_area_cmp_fn(a,c) < 0)) 
  {
    ConsistencyChecker();
  }
}

void test2(ThickFace* a, ThickFace* b, ThickFace* c){
  NewTest();
  if ((smart_uv_project_thickface_area_cmp_fn(a,b) < 0) && 
      (smart_uv_project_thickface_area_cmp_fn(b,c) < 0) && 
      (smart_uv_project_thickface_area_cmp_fn(c,a) < 0)) 
  {
    TransiveChecker();
  }
}

void test3_1(ThickFace* a, ThickFace* b){
  NewTest();
  if ((smart_uv_project_thickface_area_cmp_fn(a,b) > 0) &&
      (smart_uv_project_thickface_area_cmp_fn(b,a) > 0))
  {
    SymmetryChecker();
  }
}

void test3_2(ThickFace* a, ThickFace* b){
  NewTest();
  if ((smart_uv_project_thickface_area_cmp_fn(a,b) < 0) &&
      (smart_uv_project_thickface_area_cmp_fn(b,a) < 0))
  {
    SymmetryChecker();
  }
}

void test4(ThickFace* a){
  NewTest();
  if (smart_uv_project_thickface_area_cmp_fn(a, a) < 0 ||
      smart_uv_project_thickface_area_cmp_fn(a, a) > 0) 
  {
    ReflexivityChecker();
  }
}