#include <bits/stdc++.h>

struct facetT {
    int nummerge;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int qh_compare_nummerge(const void *p1, const void *p2) {
  const facetT *a= *((facetT *const*)p1), *b= *((facetT *const*)p2);
  return(a->nummerge - b->nummerge);
}

void test1(facetT **a,facetT **b,facetT **c){
NewTest();
if (!(qh_compare_nummerge(a,b)<0) && ! (qh_compare_nummerge(b, c)<0) && (qh_compare_nummerge(a,c)<0))
ConsistencyChecker();
}

void test2(facetT **a,facetT **b,facetT **c){
NewTest();
if ((qh_compare_nummerge(a,b)<0) && (qh_compare_nummerge(b,c)<0) && (qh_compare_nummerge(c,a)<0)) 
TransiveChecker();
}

void test3_1(facetT **a,facetT **b){
NewTest();
if ((qh_compare_nummerge(a,b)>0)&&(qh_compare_nummerge(b,a)>0))
SymmetryChecker();
}

void test3_2(facetT **a,facetT **b){
NewTest();
if ((qh_compare_nummerge(a,b)<0)&&(qh_compare_nummerge(b,a)<0))
SymmetryChecker();
}

void test4(facetT **a){
NewTest();
if (qh_compare_nummerge(a,a)<0||qh_compare_nummerge(a,a)>0) 
ReflexivityChecker();
}