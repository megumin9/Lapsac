
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int edval;
};

struct SortFaceLegacy {
    Edge es[4];
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool search_legacy_face_cmp(const SortFaceLegacy &sfa, const SortFaceLegacy &sfb) {
  if (sfa.es[0].edval != sfb.es[0].edval) {
    return sfa.es[0].edval < sfb.es[0].edval;
  }
  if (sfa.es[1].edval != sfb.es[1].edval) {
    return sfa.es[1].edval < sfb.es[1].edval;
  }
  if (sfa.es[2].edval != sfb.es[2].edval) {
    return sfa.es[2].edval < sfb.es[2].edval;
  }
  return sfa.es[3].edval < sfb.es[3].edval;
}

void test1(SortFaceLegacy a, SortFaceLegacy b, SortFaceLegacy c){
  NewTest();
  if (!search_legacy_face_cmp(a,b) && !search_legacy_face_cmp(b,c) && search_legacy_face_cmp(a,c)) 
    ConsistencyChecker();
}

void test2(SortFaceLegacy a, SortFaceLegacy b, SortFaceLegacy c){
  NewTest();
  if (search_legacy_face_cmp(a,b) && search_legacy_face_cmp(b,c) && search_legacy_face_cmp(c,a)) 
    TransiveChecker();
}

void test3_1(SortFaceLegacy a, SortFaceLegacy b){
  NewTest();
  if (search_legacy_face_cmp(a,b) && search_legacy_face_cmp(b,a))
    SymmetryChecker();
}

void test3_2(SortFaceLegacy a, SortFaceLegacy b){
  NewTest();
  if (search_legacy_face_cmp(a,b) && search_legacy_face_cmp(b,a))
    SymmetryChecker();
}

void test4(SortFaceLegacy a){
  NewTest();
  if (search_legacy_face_cmp(a, a))
    ReflexivityChecker();
}
