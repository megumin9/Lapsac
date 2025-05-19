#include <bits/stdc++.h>

struct float3 {
    float x, y, z;
};

struct float3x3 {};

namespace math {
    float determinant(const float3x3&);
}

struct VolumeProbe {
    struct Transform {
        float3 location() const;
        operator float3x3() const;
    };
    Transform object_to_world;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const VolumeProbe *a, const VolumeProbe *b) {
  float volume_a = math::determinant(float3x3(a->object_to_world));
  float volume_b = math::determinant(float3x3(b->object_to_world));
  if (volume_a != volume_b) {
    return volume_a < volume_b;
  }
  
  float3 _a = a->object_to_world.location();
  float3 _b = b->object_to_world.location();
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

void test1(const VolumeProbe *a, const VolumeProbe *b, const VolumeProbe *c){
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const VolumeProbe *a, const VolumeProbe *b, const VolumeProbe *c){
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const VolumeProbe *a, const VolumeProbe *b){
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const VolumeProbe *a){
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}