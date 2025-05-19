#include <bits/stdc++.h>
using namespace std;

struct Marker {
    int frame;
    int clip;
    int track;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool OrderByFrameLessThan(const Marker* a, const Marker* b) {
  if (a->frame == b->frame) {
    if (a->clip == b->clip) {
      return a->track < b->track;
    }
    return a->clip < b->clip;
  }
  return a->frame < b->frame;
}

void test1(const Marker* a, const Marker* b, const Marker* c) {
  NewTest();
  if (!OrderByFrameLessThan(a,b) && !OrderByFrameLessThan(b,c) && OrderByFrameLessThan(a,c))
    ConsistencyChecker();
}

void test2(const Marker* a, const Marker* b, const Marker* c) {
  NewTest();
  if (OrderByFrameLessThan(a,b) && OrderByFrameLessThan(b,c) && OrderByFrameLessThan(c,a))
    TransiveChecker();
}

void test3_1(const Marker* a, const Marker* b) {
  NewTest();
  if (OrderByFrameLessThan(a,b) && OrderByFrameLessThan(b,a))
    SymmetryChecker();
}

void test3_2(const Marker* a, const Marker* b) {
  NewTest();
  if (OrderByFrameLessThan(a,b) && OrderByFrameLessThan(b,a))
    SymmetryChecker();
}

void test4(const Marker* a) {
  NewTest();
  if (OrderByFrameLessThan(a, a))
    ReflexivityChecker();
}