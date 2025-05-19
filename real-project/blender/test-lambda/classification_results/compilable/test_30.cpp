#include <bits/stdc++.h>
using namespace std;

struct GPUDevice {
    string name;
    int index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const GPUDevice &a, const GPUDevice &b) {
  if (a.name == b.name) {
    return a.index < b.index;
  }
  return a.name < b.name;
}

void test1(GPUDevice &a, GPUDevice &b, GPUDevice &c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(GPUDevice &a, GPUDevice &b, GPUDevice &c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(GPUDevice &a, GPUDevice &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(GPUDevice &a, GPUDevice &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(GPUDevice &a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}