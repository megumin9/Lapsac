#include <bits/stdc++.h>
#include <string>

struct NameWithUsage {
    std::string name;
};

extern "C" int BLI_strcasecmp_natural(const char* a, const char* b);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda3(const NameWithUsage &a, const NameWithUsage &b) {
  return BLI_strcasecmp_natural(a.name.c_str(), b.name.c_str()) < 0;
}

void test1(const NameWithUsage &a, const NameWithUsage &b, const NameWithUsage &c) {
  NewTest();
  if (!lambda3(a, b) && !lambda3(b, c) && lambda3(a, c))
    ConsistencyChecker();
}

void test2(const NameWithUsage &a, const NameWithUsage &b, const NameWithUsage &c) {
  NewTest();
  if (lambda3(a, b) && lambda3(b, c) && lambda3(c, a))
    TransiveChecker();
}

void test3_1(const NameWithUsage &a, const NameWithUsage &b) {
  NewTest();
  if (lambda3(a, b) && lambda3(b, a))
    SymmetryChecker();
}

void test3_2(const NameWithUsage &a, const NameWithUsage &b) {
  NewTest();
  if (lambda3(a, b) && lambda3(b, a))
    SymmetryChecker();
}

void test4(const NameWithUsage &a) {
  NewTest();
  if (lambda3(a, a))
    ReflexivityChecker();
}