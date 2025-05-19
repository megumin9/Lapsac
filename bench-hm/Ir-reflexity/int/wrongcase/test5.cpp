#include <string.h>
#include <iostream>

class testclass {
  public:
    int var1, var2;
    std::string var3;    
    char * var4;
    bool var5;
};

void NewTest();
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();


int cmp(testclass *a,testclass *b) 
{   
  return strcmp(a->var4, b->var4) < 0 ? 1 : -1;
}

void test1(testclass *a, testclass *b, testclass *c) {
  NewTest();
  if (!(cmp(a, b) < 0) && !(cmp(b, c) < 0) && (cmp(a, c) < 0))
    ConsistencyChecker();
}

void test2(testclass *a, testclass *b, testclass *c) {
  NewTest();
  if ((cmp(a, b) < 0) && (cmp(b, c) < 0) && (cmp(c, a) < 0))
    TransiveChecker();
}

void test3_1(testclass *a, testclass *b) {
  NewTest();
  if ((cmp(a, b) < 0) && (cmp(b, a) < 0))
    SymmetryChecker();
}

void test3_2(testclass *a, testclass *b) {
  NewTest();
  if ((cmp(a, b) >0) && (cmp(b, a) > 0))
    SymmetryChecker();
}

void test4(testclass *a) {
  NewTest();
  if ((cmp(a, a) > 0) || (cmp(a, a) < 0))
    ReflexivityChecker();
}