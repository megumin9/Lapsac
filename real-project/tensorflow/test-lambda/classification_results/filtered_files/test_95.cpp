#include <bits/stdc++.h>

struct HloPassMetadata {
    int start_timestamp_usec() const;
    int end_timestamp_usec() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const HloPassMetadata& a, const HloPassMetadata& b) {
  return a.end_timestamp_usec() - a.start_timestamp_usec() > 
         b.end_timestamp_usec() - b.start_timestamp_usec();
}

void test1(const HloPassMetadata& a, const HloPassMetadata& b, const HloPassMetadata& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const HloPassMetadata& a, const HloPassMetadata& b, const HloPassMetadata& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const HloPassMetadata& a, const HloPassMetadata& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const HloPassMetadata& a, const HloPassMetadata& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const HloPassMetadata& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}