#include <bits/stdc++.h>
using namespace std;

struct PVert {
    int uv[2];
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int p_compare_geometric_uv(const void *a, const void *b) {
  const PVert *v1 = *(const PVert *const *)a;
  const PVert *v2 = *(const PVert *const *)b;

  if (v1->uv[0] < v2->uv[0]) {
    return -1;
  }
  if (v1->uv[0] == v2->uv[0]) {
    if (v1->uv[1] < v2->uv[1]) {
      return -1;
    }
    if (v1->uv[1] == v2->uv[1]) {
      return 0;
    }
    return 1;
  }
  return 1;
}

void test1(const PVert* const* a, const PVert* const* b, const PVert* const* c){
NewTest();
if (!(p_compare_geometric_uv(a,b)<0) && !(p_compare_geometric_uv(b,c)<0) && (p_compare_geometric_uv(a,c)<0))
ConsistencyChecker();
}

void test2(const PVert* const* a, const PVert* const* b, const PVert* const* c){
NewTest();
if ((p_compare_geometric_uv(a,b)<0) && (p_compare_geometric_uv(b,c)<0) && (p_compare_geometric_uv(c,a)<0)) 
TransiveChecker();
}

void test3_1(const PVert* const* a, const PVert* const* b){
NewTest();
if ((p_compare_geometric_uv(a,b)>0)&&(p_compare_geometric_uv(b,a)>0))
SymmetryChecker();
}

void test3_2(const PVert* const* a, const PVert* const* b){
NewTest();
if ((p_compare_geometric_uv(a,b)<0)&&(p_compare_geometric_uv(b,a)<0))
SymmetryChecker();
}

void test4(const PVert* const* a){
NewTest();
if (p_compare_geometric_uv(a, a)<0||p_compare_geometric_uv(a, a)>0) 
ReflexivityChecker();
}