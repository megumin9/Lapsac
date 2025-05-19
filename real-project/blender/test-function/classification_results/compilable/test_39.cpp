#include <bits/stdc++.h>

struct KDTreeNearest {
    int dist;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int nearest_cmp_dist(const void *a, const void *b) {
  const KDTreeNearest *kda = static_cast<const KDTreeNearest *>(a);
  const KDTreeNearest *kdb = static_cast<const KDTreeNearest *>(b);

  if (kda->dist < kdb->dist) {
    return -1;
  }
  if (kda->dist > kdb->dist) {
    return 1;
  }
  return 0;
}

void test1(void *a, void *b, void *c) {
  NewTest();
  if (!(nearest_cmp_dist(a,b)<0) && !(nearest_cmp_dist(b,c)<0) && (nearest_cmp_dist(a,c)<0))
    ConsistencyChecker();
}

void test2(void *a, void *b, void *c) {
  NewTest();
  if ((nearest_cmp_dist(a,b)<0) && (nearest_cmp_dist(b,c)<0) && (nearest_cmp_dist(c,a)<0))
    TransiveChecker();
}

void test3_1(void *a, void *b) {
  NewTest();
  if ((nearest_cmp_dist(a,b)>0)&&(nearest_cmp_dist(b,a)>0))
    SymmetryChecker();
}

void test3_2(void *a, void *b) {
  NewTest();
  if ((nearest_cmp_dist(a,b)<0)&&(nearest_cmp_dist(b,a)<0))
    SymmetryChecker();
}

void test4(void *a) {
  NewTest();
  if (nearest_cmp_dist(a, a)<0||nearest_cmp_dist(a, a)>0)
    ReflexivityChecker();
}