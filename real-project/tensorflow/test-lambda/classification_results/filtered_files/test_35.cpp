
#include <bits/stdc++.h>
#include <cstring>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const char* lhs, const char* rhs) {
  return std::strcmp(lhs, rhs) < 0;
}

void test1(const char* a, const char* b, const char* c){
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const char* a, const char* b, const char* c){
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const char* a, const char* b){
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const char* a){
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}
