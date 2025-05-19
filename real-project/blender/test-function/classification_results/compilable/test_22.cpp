#include <cstring>

struct FCurve {
    const char *rna_path;
    int array_index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int fcurve_cmp_for_cache(const void *fcu_a_p, const void *fcu_b_p) {
  const FCurve *fcu_a = *((const FCurve **)fcu_a_p);
  const FCurve *fcu_b = *((const FCurve **)fcu_b_p);
  const int cmp = strcmp(fcu_a->rna_path, fcu_b->rna_path);
  if (cmp != 0) {
    return cmp;
  }
  if (fcu_a->array_index < fcu_b->array_index) {
    return -1;
  }
  if (fcu_a->array_index > fcu_b->array_index) {
    return 1;
  }
  return 0;
}

void test1(FCurve *a, FCurve *b, FCurve *c){
NewTest();
if (!(fcurve_cmp_for_cache(&a,&b)<0) && !(fcurve_cmp_for_cache(&b,&c)<0) && (fcurve_cmp_for_cache(&a,&c)<0))
ConsistencyChecker();
}

void test2(FCurve *a, FCurve *b, FCurve *c){
NewTest();
if ((fcurve_cmp_for_cache(&a,&b)<0) && (fcurve_cmp_for_cache(&b,&c)<0) && (fcurve_cmp_for_cache(&c,&a)<0)) 
TransiveChecker();
}

void test3_1(FCurve *a, FCurve *b){
NewTest();
if ((fcurve_cmp_for_cache(&a,&b)>0)&&(fcurve_cmp_for_cache(&b,&a)>0))
SymmetryChecker();
}

void test3_2(FCurve *a, FCurve *b){
NewTest();
if ((fcurve_cmp_for_cache(&a,&b)<0)&&(fcurve_cmp_for_cache(&b,&a)<0))
SymmetryChecker();
}

void test4(FCurve *a){
NewTest();
if (fcurve_cmp_for_cache(&a, &a)<0||fcurve_cmp_for_cache(&a, &a)>0) 
ReflexivityChecker();
}