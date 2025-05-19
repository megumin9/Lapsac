#include <bits/stdc++.h>

namespace blender {
struct float2 {
    float data[2];
    float operator[](int index) const { return data[index]; }
};
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const blender::float2 &a, const blender::float2 &b) {
  float delta = b[0] - a[0];
  if (delta == 0.0f) {
    delta = b[1] - a[1];
  }
  return delta > 0.0f;
}

void test1(const blender::float2 &a, const blender::float2 &b, const blender::float2 &c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const blender::float2 &a, const blender::float2 &b, const blender::float2 &c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const blender::float2 &a, const blender::float2 &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const blender::float2 &a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}