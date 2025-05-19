#include <bits/stdc++.h>
using namespace std;

struct VertSpan {
    int min_axis;
    int max_axis;
};

struct EdgeGroupIsland {
    VertSpan vert_span;
};

int axis_pt_cmp(int a, int b);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();
#define UNLIKELY(x) (x)

int group_min_cmp_fn(const void *p1, const void *p2) {
  const EdgeGroupIsland *g1 = *(EdgeGroupIsland **)p1;
  const EdgeGroupIsland *g2 = *(EdgeGroupIsland **)p2;
  
  int test = axis_pt_cmp(g1->vert_span.min_axis, g2->vert_span.min_axis);
  if (UNLIKELY(test == 0)) {
    test = axis_pt_cmp(g1->vert_span.max_axis, g2->vert_span.max_axis);
  }
  return test;
}

void test1(EdgeGroupIsland *a, EdgeGroupIsland *b, EdgeGroupIsland *c) {
  NewTest();
  if (!(group_min_cmp_fn(a,b)<0) && !(group_min_cmp_fn(b,c)<0) && (group_min_cmp_fn(a,c)<0))
    ConsistencyChecker();
}

void test2(EdgeGroupIsland *a, EdgeGroupIsland *b, EdgeGroupIsland *c) {
  NewTest();
  if ((group_min_cmp_fn(a,b)<0) && (group_min_cmp_fn(b,c)<0) && (group_min_cmp_fn(c,a)<0))
    TransiveChecker();
}

void test3_1(EdgeGroupIsland *a, EdgeGroupIsland *b) {
  NewTest();
  if ((group_min_cmp_fn(a,b)>0)&&(group_min_cmp_fn(b,a)>0))
    SymmetryChecker();
}

void test3_2(EdgeGroupIsland *a, EdgeGroupIsland *b) {
  NewTest();
  if ((group_min_cmp_fn(a,b)<0)&&(group_min_cmp_fn(b,a)<0))
    SymmetryChecker();
}

void test4(EdgeGroupIsland *a) {
  NewTest();
  if (group_min_cmp_fn(a, a)<0||group_min_cmp_fn(a, a)>0)
    ReflexivityChecker();
}