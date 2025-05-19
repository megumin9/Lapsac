
#include <bits/stdc++.h>
using namespace std;

struct areanode {
    double area;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int cmpfunc(const void *a, const void *b) {
  const double v1 = (*(areanode **)a)->area;
  const double v2 = (*(areanode **)b)->area;
  
  if (v1 == v2)
    return (*(areanode **)a) - (*(areanode **)b);
  else
    return (v1 > v2) ? 1 : -1;
}

void test1(areanode* a, areanode* b, areanode* c) {
  NewTest();
  if (!(cmpfunc(a,b)<0) && !(cmpfunc(b,c)<0) && (cmpfunc(a,c)<0))
    ConsistencyChecker();
}

void test2(areanode* a, areanode* b, areanode* c) {
  NewTest();
  if ((cmpfunc(a,b)<0) && (cmpfunc(b,c)<0) && (cmpfunc(c,a)<0))
    TransiveChecker();
}

void test3_1(areanode* a, areanode* b) {
  NewTest();
  if ((cmpfunc(a,b)>0)&&(cmpfunc(b,a)>0))
    SymmetryChecker();
}

void test3_2(areanode* a, areanode* b) {
  NewTest();
  if ((cmpfunc(a,b)<0)&&(cmpfunc(b,a)<0))
    SymmetryChecker();
}

void test4(areanode* a) {
  NewTest();
  if (cmpfunc(a,a)<0||cmpfunc(a,a)>0) 
    ReflexivityChecker();
}
