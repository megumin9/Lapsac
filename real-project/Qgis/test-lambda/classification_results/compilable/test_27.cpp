
#include <bits/stdc++.h>
#include <cstdint>

extern uint32_t* mVertexCoords;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(uint32_t a, uint32_t b) {
  return mVertexCoords[a * 3 + 1] > mVertexCoords[b * 3 + 1];
}

void test1(uint32_t a, uint32_t b, uint32_t c) {
  NewTest();
  if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(uint32_t a, uint32_t b, uint32_t c) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(uint32_t a, uint32_t b) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test3_2(uint32_t a, uint32_t b) {
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(uint32_t a) {
  NewTest();
  if (lambda2(a, a))
    ReflexivityChecker();
}
