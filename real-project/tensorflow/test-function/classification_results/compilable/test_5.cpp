#include <bits/stdc++.h>
using namespace std;

struct DataType {
    int start_time_ps() const;
    int end_time_ps() const;
};

class Timespan {
public:
    static Timespan FromEndPoints(int start, int end);
    static bool ByDuration(const Timespan& a, const Timespan& b);
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool CompareByDuration(const DataType* a, const DataType* b) {
  return Timespan::ByDuration(
      Timespan::FromEndPoints(a->start_time_ps(), a->end_time_ps()),
      Timespan::FromEndPoints(b->start_time_ps(), b->end_time_ps()));
}

void test1(DataType* a, DataType* b, DataType* c) {
  NewTest();
  if (!CompareByDuration(a,b) && !CompareByDuration(b,c) && CompareByDuration(a,c))
    ConsistencyChecker();
}

void test2(DataType* a, DataType* b, DataType* c) {
  NewTest();
  if (CompareByDuration(a,b) && CompareByDuration(b,c) && CompareByDuration(c,a))
    TransiveChecker();
}

void test3_1(DataType* a, DataType* b) {
  NewTest();
  if (CompareByDuration(a,b) && CompareByDuration(b,a))
    SymmetryChecker();
}

void test3_2(DataType* a, DataType* b) {
  NewTest();
  if (CompareByDuration(a,b) && CompareByDuration(b,a))
    SymmetryChecker();
}

void test4(DataType* a) {
  NewTest();
  if (CompareByDuration(a,a))
    ReflexivityChecker();
}