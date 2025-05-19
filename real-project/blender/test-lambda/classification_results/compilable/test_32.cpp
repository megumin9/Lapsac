#include <bits/stdc++.h>

struct SearchItem {
    int main_group_length;
    int total_length;
};

extern std::vector<SearchItem> items_;
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(int a, int b) {
  const SearchItem &item_a = items_[a];
  const SearchItem &item_b = items_[b];
  
  return item_a.main_group_length < item_b.main_group_length ||
         (item_a.main_group_length == item_b.main_group_length &&
          item_a.total_length < item_b.total_length);
}

void test1(int a, int b, int c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) {
        ConsistencyChecker();
    }
}

void test2(int a, int b, int c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) {
        TransiveChecker();
    }
}

void test3_1(int a, int b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) {
        SymmetryChecker();
    }
}

void test4(int a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}