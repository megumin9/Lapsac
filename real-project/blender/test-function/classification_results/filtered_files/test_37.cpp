#include <bits/stdc++.h>

struct DepthID {
    int id;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int depth_id_cmp(const void *v1, const void *v2) {
  const DepthID *d1 = static_cast<const DepthID *>(v1), *d2 = static_cast<const DepthID *>(v2);
  if (d1->id < d2->id) {
    return -1;
  }
  if (d1->id > d2->id) {
    return 1;
  }
  return 0;
}

void test1(DepthID a, DepthID b, DepthID c){
NewTest();
if (!(depth_id_cmp(&a,&b)<0) && !(depth_id_cmp(&b,&c)<0) && (depth_id_cmp(&a,&c)<0))
ConsistencyChecker();
}

void test2(DepthID a, DepthID b, DepthID c){
NewTest();
if ((depth_id_cmp(&a,&b)<0) && (depth_id_cmp(&b,&c)<0) && (depth_id_cmp(&c,&a)<0)) 
TransiveChecker();
}

void test3_1(DepthID a, DepthID b){
NewTest();
if ((depth_id_cmp(&a,&b)>0)&&(depth_id_cmp(&b,&a)>0))
SymmetryChecker();
}

void test3_2(DepthID a, DepthID b){
NewTest();
if ((depth_id_cmp(&a,&b)<0)&&(depth_id_cmp(&b,&a)<0))
SymmetryChecker();
}

void test4(DepthID a){
NewTest();
if (depth_id_cmp(&a, &a)<0||depth_id_cmp(&a, &a)>0) 
ReflexivityChecker();
}