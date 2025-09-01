#include <bits/stdc++.h>

int formatSortPriority(const std::string&);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_17(const std::string &lhs, const std::string &rhs) {
  const int lhsPriority = formatSortPriority(lhs);
  const int rhsPriority = formatSortPriority(rhs);
  return lhsPriority == rhsPriority ? lhs < rhs : lhsPriority > rhsPriority;
}

void test1(const std::string &a, const std::string &b, const std::string &c) {
    NewTest();
    if (!compare_17(a,b) && !compare_17(b,c) && compare_17(a,c))
        ConsistencyChecker();
}

void test2(const std::string &a, const std::string &b, const std::string &c) {
    NewTest();
    if (compare_17(a,b) && compare_17(b,c) && compare_17(c,a))
        TransiveChecker();
}

void test3_1(const std::string &a, const std::string &b) {
    NewTest();
    if (compare_17(a,b) && compare_17(b,a))
        SymmetryChecker();
}

void test3_2(const std::string &a, const std::string &b) {
    NewTest();
    if (compare_17(a,b) && compare_17(b,a))
        SymmetryChecker();
}

void test4(const std::string &a) {
    NewTest();
    if (compare_17(a, a))
        ReflexivityChecker();
}