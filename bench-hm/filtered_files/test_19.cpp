#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

class testclass {
public:
    const char* var4;
};

bool cmp(testclass *a, testclass *b) {
  if (strlen(a->var4) != strlen(b->var4)) {
    return strlen(a->var4) < strlen(b->var4);
  }
  return false;
}

void test1(testclass *a, testclass *b, testclass *c) {
    NewTest();
    if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
        ConsistencyChecker();
}

void test2(testclass *a, testclass *b, testclass *c) {
    NewTest();
    if (cmp(a,b) && cmp(b,c) && cmp(c,a))
        TransiveChecker();
}

void test3_1(testclass *a, testclass *b) {
    NewTest();
    if (cmp(a,b) && cmp(b,a))
        SymmetryChecker();
}

void test3_2(testclass *a, testclass *b) {
    NewTest();
    if (cmp(a,b) && cmp(b,a))
        SymmetryChecker();
}

void test4(testclass *a) {
    NewTest();
    if (cmp(a, a))
        ReflexivityChecker();
}