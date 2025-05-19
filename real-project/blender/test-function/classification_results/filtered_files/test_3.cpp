#include <bits/stdc++.h>
using namespace std;

struct Intersection {
    int t;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int intersections_compare(const void *a, const void *b) {
  const Intersection *isect_a = (const Intersection *)a;
  const Intersection *isect_b = (const Intersection *)b;

  if (isect_a->t < isect_b->t) return -1;
  if (isect_a->t > isect_b->t) return 1;
  return 0;
}

void test1(const void *a, const void *b, const void *c){
  NewTest();
  if (!(intersections_compare(a,b)<0) && !(intersections_compare(b,c)<0) && (intersections_compare(a,c)<0))
    ConsistencyChecker();
}

void test2(const void *a, const void *b, const void *c){
  NewTest();
  if ((intersections_compare(a,b)<0) && (intersections_compare(b,c)<0) && (intersections_compare(c,a)<0)) 
    TransiveChecker();
}

void test3_1(const void *a, const void *b){
  NewTest();
  if ((intersections_compare(a,b)<0)&&(intersections_compare(b,a)<0))
    SymmetryChecker();
}

void test3_2(const void *a, const void *b){
  NewTest();
  if ((intersections_compare(a,b)>0)&&(intersections_compare(b,a)>0))
    SymmetryChecker();
}

void test4(const void *a){
  NewTest();
  if (intersections_compare(a, a)<0||intersections_compare(a, a)>0) 
    ReflexivityChecker();
}