#include <bits/stdc++.h>
using namespace std;

struct Camera {
    int camera_id;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const Camera& camera1, const Camera& camera2) {
  return camera1.camera_id < camera2.camera_id;
}

void test1(Camera a, Camera b, Camera c){
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
  ConsistencyChecker();
}

void test2(Camera a, Camera b, Camera c){
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
  TransiveChecker();
}

void test3_1(Camera a, Camera b){
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
  SymmetryChecker();
}

void test4(Camera a){
  NewTest();
  if (lambda1(a, a))
  ReflexivityChecker();
}