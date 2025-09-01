#include <bits/stdc++.h>
using namespace std;

struct GroupSnapshotNamespace {
    int group_pool;
    int group_id;
    int group_snapshot_id;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_13(const GroupSnapshotNamespace& a, const GroupSnapshotNamespace& b) {
  if (a.group_pool < b.group_pool) {
    return true;
  } else if (a.group_id < b.group_id) {
    return true;
  } else {
    return (a.group_snapshot_id < b.group_snapshot_id);
  }
  return false;
}

void test1(const GroupSnapshotNamespace& a, const GroupSnapshotNamespace& b, const GroupSnapshotNamespace& c) {
  NewTest();
  if (!compare_13(a,b) && !compare_13(b,c) && compare_13(a,c))
    ConsistencyChecker();
}

void test2(const GroupSnapshotNamespace& a, const GroupSnapshotNamespace& b, const GroupSnapshotNamespace& c) {
  NewTest();
  if (compare_13(a,b) && compare_13(b,c) && compare_13(c,a))
    TransiveChecker();
}

void test3_1(const GroupSnapshotNamespace& a, const GroupSnapshotNamespace& b) {
  NewTest();
  if (compare_13(a,b) && compare_13(b,a))
    SymmetryChecker();
}

void test3_2(const GroupSnapshotNamespace& a, const GroupSnapshotNamespace& b) {
  NewTest();
  if (compare_13(a,b) && compare_13(b,a))
    SymmetryChecker();
}

void test4(const GroupSnapshotNamespace& a) {
  NewTest();
  if (compare_13(a, a))
    ReflexivityChecker();
}