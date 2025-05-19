#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

struct GPUSelectResult {
    int depth;
    uint id;
};

void BLI_endian_switch_uint32(uint*);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int gpu_select_buffer_depth_id_cmp(const void *sel_a_p, const void *sel_b_p) {
  GPUSelectResult *a = (GPUSelectResult *)sel_a_p;
  GPUSelectResult *b = (GPUSelectResult *)sel_b_p;

  if (a->depth < b->depth) {
    return -1;
  }
  if (a->depth > b->depth) {
    return 1;
  }

  uint sel_a = a->id;
  uint sel_b = b->id;

#ifdef __BIG_ENDIAN__
  BLI_endian_switch_uint32(&sel_a);
  BLI_endian_switch_uint32(&sel_b);
#endif

  if (sel_a < sel_b) {
    return -1;
  }
  if (sel_a > sel_b) {
    return 1;
  }
  return 0;
}

void test1(const void* a, const void* b, const void* c){
NewTest();
if (!(gpu_select_buffer_depth_id_cmp(a,b)<0) && !(gpu_select_buffer_depth_id_cmp(b,c)<0) && (gpu_select_buffer_depth_id_cmp(a,c)<0))
ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
NewTest();
if ((gpu_select_buffer_depth_id_cmp(a,b)<0) && (gpu_select_buffer_depth_id_cmp(b,c)<0) && (gpu_select_buffer_depth_id_cmp(c,a)<0)) 
TransiveChecker();
}

void test3_1(const void* a, const void* b){
NewTest();
if ((gpu_select_buffer_depth_id_cmp(a,b)>0)&&(gpu_select_buffer_depth_id_cmp(b,a)>0))
SymmetryChecker();
}

void test3_2(const void* a, const void* b){
NewTest();
if ((gpu_select_buffer_depth_id_cmp(a,b)<0)&&(gpu_select_buffer_depth_id_cmp(b,a)<0))
SymmetryChecker();
}

void test4(const void* a){
NewTest();
if (gpu_select_buffer_depth_id_cmp(a, a)<0||gpu_select_buffer_depth_id_cmp(a, a)>0) 
ReflexivityChecker();
}