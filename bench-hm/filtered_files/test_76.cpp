#include <bits/stdc++.h>
using namespace std;

struct testclass {
    int var1;
    char* var4;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(testclass *a, testclass *b) {
  int x = strlen(a->var4);
  int y = strlen(b->var4);
  
  if (x != y)
    return x < y;

  if (a->var1 != b->var1)
    return a->var1 < b->var1;
  
  return false;
}

void test1(testclass *a, testclass *b, testclass *c){
NewTest();
if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
ConsistencyChecker();
}

void test2(testclass *a, testclass *b, testclass *c){
NewTest();
if (cmp(a,b) && cmp(b,c) && cmp(c,a))
TransiveChecker();
}

void test3_1(testclass *a,testclass *b){
NewTest();
if (cmp(a,b) && cmp(b,a))
SymmetryChecker();
}

void test3_2(testclass *a,testclass *b){
NewTest();
if (cmp(a,b) && cmp(b,a))
SymmetryChecker();
}

void test4(testclass *a){
NewTest();
if (cmp(a, a))
ReflexivityChecker();
}