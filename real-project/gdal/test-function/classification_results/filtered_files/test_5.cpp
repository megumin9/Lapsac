#include <bits/stdc++.h>
using namespace std;

struct mergeT {
    int mergetype;
    int angle;
};

int qh_compare_anglemerge(const void *p1, const void *p2);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int qh_compare_anglemerge(const void *p1, const void *p2) {
  const mergeT *a= *((mergeT *const*)p1), *b= *((mergeT *const*)p2);

  if (a->mergetype != b->mergetype)
    return (a->mergetype < b->mergetype ? 1 : -1); 
  else
    return (a->angle > b->angle ? 1 : -1);
}

void test1(mergeT** a, mergeT** b, mergeT** c){
NewTest();
if (!(qh_compare_anglemerge(a,b)<0) && !(qh_compare_anglemerge(b,c)<0) && (qh_compare_anglemerge(a,c)<0)) 
ConsistencyChecker();
}

void test2(mergeT** a, mergeT** b, mergeT** c){
NewTest();
if ((qh_compare_anglemerge(a,b)<0) && (qh_compare_anglemerge(b,c)<0) && (qh_compare_anglemerge(c,a)<0)) 
TransiveChecker();
}

void test3_1(mergeT** a, mergeT** b){
NewTest();
if ((qh_compare_anglemerge(a,b)>0)&&(qh_compare_anglemerge(b,a)>0))
SymmetryChecker();
}

void test3_2(mergeT** a, mergeT** b){
NewTest();
if ((qh_compare_anglemerge(a,b)<0)&&(qh_compare_anglemerge(b,a)<0))
SymmetryChecker();
}

void test4(mergeT** a){
NewTest();
if (qh_compare_anglemerge(a, a)<0 || qh_compare_anglemerge(a, a)>0) 
ReflexivityChecker();
}