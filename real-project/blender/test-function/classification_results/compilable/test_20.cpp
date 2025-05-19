
#include <bits/stdc++.h>
using namespace std;

struct SortFace {
    bool invalid;
    int numverts;
    vector<int> verts;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool search_face_cmp(const SortFace &sp1, const SortFace &sp2) {
  if (sp1.invalid || sp2.invalid) {
    return sp1.invalid < sp2.invalid;
  }
  
  const int max_idx = min(sp1.numverts, sp2.numverts);
  for (int idx = 0; idx < max_idx; idx++) {
    const int v1_i = sp1.verts[idx];
    const int v2_i = sp2.verts[idx];
    if (v1_i != v2_i) {
      return v1_i < v2_i;
    }
  }
  return sp1.numverts < sp2.numverts;
}

void test1(SortFace a, SortFace b, SortFace c){
NewTest();
if (!search_face_cmp(a,b) && !search_face_cmp(b,c) && search_face_cmp(a,c))
ConsistencyChecker();
}

void test2(SortFace a, SortFace b, SortFace c){
NewTest();
if (search_face_cmp(a,b) && search_face_cmp(b,c) && search_face_cmp(c,a))
TransiveChecker();
}

void test3_1(SortFace a, SortFace b){
NewTest();
if (search_face_cmp(a,b) && search_face_cmp(b,a))
SymmetryChecker();
}

void test3_2(SortFace a, SortFace b){
NewTest();
if (search_face_cmp(a,b) && search_face_cmp(b,a))
SymmetryChecker();
}

void test4(SortFace a){
NewTest();
if (search_face_cmp(a, a))
ReflexivityChecker();
}
