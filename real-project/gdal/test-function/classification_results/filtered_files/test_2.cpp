#include <bits/stdc++.h>
using namespace std;

struct facetT {
    int id;
    int visitid;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int qh_compare_facetvisit(const void *p1, const void *p2) {
  const facetT *a= *((facetT *const*)p1), *b= *((facetT *const*)p2);
  int i,j;
  
  if (!(i= (int)a->visitid)) 
    i= (int)(0 - a->id); 
  if (!(j= (int)b->visitid))
    j= (int)(0 - b->id);
  return(i - j);
}

void test1(facetT *a, facetT *b, facetT *c){
  NewTest();
  if (!(qh_compare_facetvisit(a,b)<0) && !(qh_compare_facetvisit(b,c)<0) && (qh_compare_facetvisit(a,c)<0)) 
    ConsistencyChecker();
}

void test2(facetT *a, facetT *b, facetT *c){
  NewTest();
  if ((qh_compare_facetvisit(a,b)<0) && (qh_compare_facetvisit(b,c)<0) && (qh_compare_facetvisit(c,a)<0))
    TransiveChecker();
}

void test3_1(facetT *a, facetT *b){
  NewTest();
  if ((qh_compare_facetvisit(a,b)<0)&&(qh_compare_facetvisit(b,a)<0))
    SymmetryChecker();
}

void test3_2(facetT *a, facetT *b){
  NewTest();
  if ((qh_compare_facetvisit(a,b)<0)&&(qh_compare_facetvisit(b,a)<0))
    SymmetryChecker();
}

void test4(facetT *a){
  NewTest();
  if (qh_compare_facetvisit(a,a)<0 || qh_compare_facetvisit(a,a)>0)
    ReflexivityChecker();
}