
#include <bits/stdc++.h>
struct MDeformWeight {
    int weight;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int inv_cmp_mdef_vert_weights(const void *a1, const void *a2) {
  const MDeformWeight *dw1 = static_cast<const MDeformWeight *>(a1);
  const MDeformWeight *dw2 = static_cast<const MDeformWeight *>(a2);

  if (dw1->weight < dw2->weight) {
    return 1;
  }
  if (dw1->weight > dw2->weight) {
    return -1;
  }
  if (&dw1 < &dw2) {
    return 1; 
  }
  return -1;
}

void test1(const MDeformWeight* a, const MDeformWeight* b, const MDeformWeight* c){
NewTest();
if (!(inv_cmp_mdef_vert_weights(a,b)<0) && !(inv_cmp_mdef_vert_weights(b,c)<0) && (inv_cmp_mdef_vert_weights(a,c)<0))
ConsistencyChecker();
}

void test2(const MDeformWeight* a, const MDeformWeight* b, const MDeformWeight* c){
NewTest();
if ((inv_cmp_mdef_vert_weights(a,b)<0) && (inv_cmp_mdef_vert_weights(b,c)<0) && (inv_cmp_mdef_vert_weights(c,a)<0))
TransiveChecker();
}

void test3_1(const MDeformWeight* a, const MDeformWeight* b){
NewTest();
if ((inv_cmp_mdef_vert_weights(a,b)>0)&&(inv_cmp_mdef_vert_weights(b,a)>0))
SymmetryChecker();
}

void test3_2(const MDeformWeight* a, const MDeformWeight* b){
NewTest();
if ((inv_cmp_mdef_vert_weights(a,b)<0)&&(inv_cmp_mdef_vert_weights(b,a)<0))
SymmetryChecker();
}

void test4(const MDeformWeight* a){
NewTest();
if (inv_cmp_mdef_vert_weights(a, a)<0 || inv_cmp_mdef_vert_weights(a, a)>0)
ReflexivityChecker();
}
