#include <bits/stdc++.h>
#include <cstring>

struct testclass {
    char* var4;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(testclass *a, testclass *b) {
  if (strcmp(a->var4, b->var4) != 0)
    return strcmp(a->var4, b->var4) < 0;
  return false;
}

void test1(testclass* a, testclass* b, testclass* c){
NewTest();
if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
ConsistencyChecker();
}

void test2(testclass* a, testclass* b, testclass* c){
NewTest();
if (cmp(a,b) && cmp(b,c) && cmp(c,a))
TransiveChecker();
}

void test3_1(testclass* a, testclass* b){
NewTest();
if (cmp(a,b) && cmp(b,a))
SymmetryChecker();
}

void test3_2(testclass* a, testclass* b){
NewTest();
if (cmp(a,b) && cmp(b,a))
SymmetryChecker();
}

void test4(testclass* a){
NewTest();
if (cmp(a, a))
ReflexivityChecker();
}