#include <bits/stdc++.h>

struct LayoutPanelState {
    int last_used;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const LayoutPanelState *a, const LayoutPanelState *b) {
  return a->last_used < b->last_used;
}

void test1(const LayoutPanelState *a, const LayoutPanelState *b, const LayoutPanelState *c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const LayoutPanelState *a, const LayoutPanelState *b, const LayoutPanelState *c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const LayoutPanelState *a, const LayoutPanelState *b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const LayoutPanelState *a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}