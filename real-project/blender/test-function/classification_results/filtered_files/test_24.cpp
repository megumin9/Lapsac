#include <bits/stdc++.h>
using uint = unsigned int;
struct GPUSelectResult {
    uint id;
};
void BLI_endian_switch_uint32(uint *val);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int gpu_bone_select_buffer_cmp(const void *sel_a_p, const void *sel_b_p) {
  uint sel_a = ((GPUSelectResult *)sel_a_p)->id;
  uint sel_b = ((GPUSelectResult *)sel_b_p)->id;

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

void test1(void *a, void *b, void *c) {
  NewTest();
  if (!(gpu_bone_select_buffer_cmp(a, b) < 0) && 
      !(gpu_bone_select_buffer_cmp(b, c) < 0) && 
      (gpu_bone_select_buffer_cmp(a, c) < 0)) {
    ConsistencyChecker();
  }
}

void test2(void *a, void *b, void *c) {
  NewTest();
  if ((gpu_bone_select_buffer_cmp(a, b) < 0) && 
      (gpu_bone_select_buffer_cmp(b, c) < 0) && 
      (gpu_bone_select_buffer_cmp(c, a) < 0)) {
    TransiveChecker();
  }
}

void test3_1(void *a, void *b) {
  NewTest();
  if ((gpu_bone_select_buffer_cmp(a, b) > 0) && 
      (gpu_bone_select_buffer_cmp(b, a) > 0)) {
    SymmetryChecker();
  }
}

void test3_2(void *a, void *b) {
  NewTest();
  if ((gpu_bone_select_buffer_cmp(a, b) < 0) && 
      (gpu_bone_select_buffer_cmp(b, a) < 0)) {
    SymmetryChecker();
  }
}

void test4(void *a) {
  NewTest();
  if (gpu_bone_select_buffer_cmp(a, a) < 0 || 
      gpu_bone_select_buffer_cmp(a, a) > 0) {
    ReflexivityChecker();
  }
}