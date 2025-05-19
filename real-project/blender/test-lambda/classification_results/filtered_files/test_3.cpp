#include <bits/stdc++.h>
using namespace std;

struct float3 {
    int x, y, z;
};

struct SphereProbe {
    int volume;
    float3 location;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const SphereProbe *a, const SphereProbe *b) {
 
  if (a->volume != b->volume) {
    return a->volume < b->volume;
  }
  
  float3 _a = a->location;
  float3 _b = b->location;
  if (_a.x != _b.x) {
    return _a.x < _b.x;
  }
  if (_a.y != _b.y) {
    return _a.y < _b.y;
  }
  if (_a.z != _b.z) {
    return _a.z < _b.z;
  }

  return a < b;
}

void test1(const SphereProbe *a, const SphereProbe *b, const SphereProbe *c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}
/*
void test2(const SphereProbe *a, const SphereProbe *b, const SphereProbe *c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}


void test3_1(const SphereProbe *a, const SphereProbe *b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const SphereProbe *a, const SphereProbe *b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const SphereProbe *a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}*/