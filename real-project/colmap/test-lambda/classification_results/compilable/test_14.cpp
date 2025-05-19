#include <bits/stdc++.h>
#include <vector>

namespace SceneClustering {
struct Cluster {
    std::vector<int> image_ids;
};
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const SceneClustering::Cluster* cluster1,
             const SceneClustering::Cluster* cluster2) {
  return cluster1->image_ids.size() > cluster2->image_ids.size();
}

void test1(const SceneClustering::Cluster* a, const SceneClustering::Cluster* b, const SceneClustering::Cluster* c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
    ConsistencyChecker();
  }
}

void test2(const SceneClustering::Cluster* a, const SceneClustering::Cluster* b, const SceneClustering::Cluster* c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
    TransiveChecker();
  }
}

void test3_1(const SceneClustering::Cluster* a, const SceneClustering::Cluster* b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(const SceneClustering::Cluster* a, const SceneClustering::Cluster* b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) {
    SymmetryChecker();
  }
}

void test4(const SceneClustering::Cluster* a) {
  NewTest();
  if (lambda0(a, a)) {
    ReflexivityChecker();
  }
}