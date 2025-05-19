#include <bits/stdc++.h>
using namespace std;

struct Zone {
    int depth;
};

struct TreeZones {
    Zone** zones;
};

TreeZones* tree_zones_;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const int zone_a, const int zone_b) {
  return tree_zones_->zones[zone_a]->depth > tree_zones_->zones[zone_b]->depth;
}

void test1(int a, int b, int c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
    ConsistencyChecker();
}

void test2(int a, int b, int c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
    TransiveChecker();
}

void test3_1(int a, int b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test3_2(int a, int b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test4(int a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}