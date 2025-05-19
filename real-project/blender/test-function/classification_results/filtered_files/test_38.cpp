#include <bits/stdc++.h>

struct DepthID {
    int depth;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int depth_cmp(const void *v1, const void *v2) {
  const DepthID *d1 = static_cast<const DepthID *>(v1), *d2 = static_cast<const DepthID *>(v2);
  if (d1->depth < d2->depth) {
    return -1;
  }
  if (d1->depth > d2->depth) {
    return 1;
  }
  return 0;
}

void test1(void* a, void* b, void* c){
NewTest();
if (!(depth_cmp(a,b)<0) && !(depth_cmp(b,c)<0) && (depth_cmp(a,c)<0))
ConsistencyChecker();
}

void test2(void* a, void* b, void* c){
NewTest();
if ((depth_cmp(a,b)<0) && (depth_cmp(b,c)<0) && (depth_cmp(c,a)<0))
TransiveChecker();
}

void test3_1(void* a, void* b){
NewTest();
if ((depth_cmp(a,b)>0)&&(depth_cmp(b,a)>0))
SymmetryChecker();
}

void test3_2(void* a, void* b){
NewTest();
if ((depth_cmp(a,b)<0)&&(depth_cmp(b,a)<0))
SymmetryChecker();
}

void test4(void* a){
NewTest();
if (depth_cmp(a, a)<0||depth_cmp(a, a)>0) 
ReflexivityChecker();
}