
#include <bits/stdc++.h>

struct CollItemSearch {
    std::string name;
};

extern int BLI_strcasecmp_natural(const char *a, const char *b);

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::unique_ptr<CollItemSearch> &a, const std::unique_ptr<CollItemSearch> &b) {
  return BLI_strcasecmp_natural(a->name.c_str(), b->name.c_str()) < 0;
}

void test1(const std::unique_ptr<CollItemSearch> &a, const std::unique_ptr<CollItemSearch> &b, const std::unique_ptr<CollItemSearch> &c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const std::unique_ptr<CollItemSearch> &a, const std::unique_ptr<CollItemSearch> &b, const std::unique_ptr<CollItemSearch> &c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const std::unique_ptr<CollItemSearch> &a, const std::unique_ptr<CollItemSearch> &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const std::unique_ptr<CollItemSearch> &a, const std::unique_ptr<CollItemSearch> &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const std::unique_ptr<CollItemSearch> &a) {
  NewTest();
  if (lambda0(a,a))
    ReflexivityChecker();
}
