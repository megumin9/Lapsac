
#include <bits/stdc++.h>

struct bNode {
    int flag;
    bNode* parent;
};

enum {
    NODE_SELECT = 1,
    NODE_ACTIVE = 2,
    NODE_BACKGROUND = 4
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_node_depth(const bNode *a, const bNode *b) {
  bool a_select = (a->flag & NODE_SELECT) != 0, b_select = (b->flag & NODE_SELECT) != 0;
  bool a_active = (a->flag & NODE_ACTIVE) != 0, b_active = (b->flag & NODE_ACTIVE) != 0;

  for (bNode *parent = a->parent; parent; parent = parent->parent) {
    if (parent == b) {
      return false;
    }
    if (parent->flag & NODE_ACTIVE) {
      a_active = true;
    }
    if (parent->flag & NODE_SELECT) {
      a_select = true;
    }
  }
  for (bNode *parent = b->parent; parent; parent = parent->parent) {
    if (parent == a) {
      return true;
    }
    if (parent->flag & NODE_ACTIVE) {
      b_active = true;
    }
    if (parent->flag & NODE_SELECT) {
      b_select = true;
    }
  }

  if ((a->flag & NODE_BACKGROUND) && !(b->flag & NODE_BACKGROUND)) {
    return true;
  }
  if ((b->flag & NODE_BACKGROUND) && !(a->flag & NODE_BACKGROUND)) {
    return false;
  }

  if (a_active && !b_active) {
    return false;
  }
  if (b_active && !a_active) {
    return true;
  }
  if (!b_select && (a_active || a_select)) {
    return false;
  }
  if (!a_select && (b_active || b_select)) {
    return true;
  }

  return false;
}

void test1(const bNode *a, const bNode *b, const bNode *c) {
  NewTest();
  if (!compare_node_depth(a, b) && !compare_node_depth(b, c) && compare_node_depth(a, c)) {
    ConsistencyChecker();
  }
}

void test2(const bNode *a, const bNode *b, const bNode *c) {
  NewTest();
  if (compare_node_depth(a, b) && compare_node_depth(b, c) && compare_node_depth(c, a)) {
    TransiveChecker();
  }
}

void test3_1(const bNode *a, const bNode *b) {
  NewTest();
  if (compare_node_depth(a, b) && compare_node_depth(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(const bNode *a, const bNode *b) {
  NewTest();
  if (compare_node_depth(a, b) && compare_node_depth(b, a)) {
    SymmetryChecker();
  }
}

void test4(const bNode *a) {
  NewTest();
  if (compare_node_depth(a, a)) {
    ReflexivityChecker();
  }
}
