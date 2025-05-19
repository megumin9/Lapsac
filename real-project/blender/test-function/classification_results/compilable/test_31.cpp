#include <string.h>

struct ID {
    char name[256];
};

struct Object {
    ID id;
};

struct Base {
    Object* object;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int ds_base_sorting_cmp(const void *base1_ptr, const void *base2_ptr) {
  const Base *b1 = *((const Base **)base1_ptr);
  const Base *b2 = *((const Base **)base2_ptr);

  return strcmp(b1->object->id.name + 2, b2->object->id.name + 2);
}

void test1(const void* a, const void* b, const void* c) {
  NewTest();
  if (!(ds_base_sorting_cmp(a, b) < 0) && 
      !(ds_base_sorting_cmp(b, c) < 0) && 
      (ds_base_sorting_cmp(a, c) < 0)) {
    ConsistencyChecker();
  }
}

void test2(const void* a, const void* b, const void* c) {
  NewTest();
  if ((ds_base_sorting_cmp(a, b) < 0) && 
      (ds_base_sorting_cmp(b, c) < 0) && 
      (ds_base_sorting_cmp(c, a) < 0)) {
    TransiveChecker();
  }
}

void test3_1(const void* a, const void* b) {
  NewTest();
  if ((ds_base_sorting_cmp(a, b) > 0) && (ds_base_sorting_cmp(b, a) > 0)) {
    SymmetryChecker();
  }
}

void test3_2(const void* a, const void* b) {
  NewTest();
  if ((ds_base_sorting_cmp(a, b) < 0) && (ds_base_sorting_cmp(b, a) < 0)) {
    SymmetryChecker();
  }
}

void test4(const void* a) {
  NewTest();
  if (ds_base_sorting_cmp(a, a) < 0 || ds_base_sorting_cmp(a, a) > 0) {
    ReflexivityChecker();
  }
}