#include <bits/stdc++.h>
struct bNodeLink {
    int multi_input_sort_id;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const bNodeLink *a, const bNodeLink *b) {
  return a->multi_input_sort_id > b->multi_input_sort_id;
}

void test1(const bNodeLink *a, const bNodeLink *b, const bNodeLink *c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) {
    ConsistencyChecker();
  }
}

void test2(const bNodeLink *a, const bNodeLink *b, const bNodeLink *c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) {
    TransiveChecker();
  }
}

void test3_1(const bNodeLink *a, const bNodeLink *b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a)) {
    SymmetryChecker();
  }
}

void test3_2(const bNodeLink *a, const bNodeLink *b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a)) {
    SymmetryChecker();
  }
}

void test4(const bNodeLink *a) {
  NewTest();
  if (lambda0(a, a)) {
    ReflexivityChecker();
  }
}