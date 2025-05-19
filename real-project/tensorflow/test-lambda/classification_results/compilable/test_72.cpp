#include <bits/stdc++.h>

namespace ProvidedDelegateList {
    struct ProvidedDelegate {
        int rank;
    };
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ProvidedDelegateList::ProvidedDelegate& a, const ProvidedDelegateList::ProvidedDelegate& b) {
  return a.rank < b.rank;
}

void test1(const ProvidedDelegateList::ProvidedDelegate& a, const ProvidedDelegateList::ProvidedDelegate& b, const ProvidedDelegateList::ProvidedDelegate& c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) 
    ConsistencyChecker();
}

void test2(const ProvidedDelegateList::ProvidedDelegate& a, const ProvidedDelegateList::ProvidedDelegate& b, const ProvidedDelegateList::ProvidedDelegate& c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) 
    TransiveChecker();
}

void test3_1(const ProvidedDelegateList::ProvidedDelegate& a, const ProvidedDelegateList::ProvidedDelegate& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) 
    SymmetryChecker();
}

void test3_2(const ProvidedDelegateList::ProvidedDelegate& a, const ProvidedDelegateList::ProvidedDelegate& b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a)) 
    SymmetryChecker();
}

void test4(const ProvidedDelegateList::ProvidedDelegate& a) {
  NewTest();
  if (lambda0(a, a)) 
    ReflexivityChecker();
}