#include <iostream>
#include <cstring>
#include <string>
struct testclass {
    int var1;
    bool var5;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int cmp(testclass *a, testclass *b) {
if (a->var5 && !b->var5)
    return 1;
  
  if (a->var1 < b->var1)
    return 1;
  
  if (!a->var5 && b->var5)
    return -1;

  if (a->var1 > b->var1)
    return -1;

  return 0;
}

void test1(testclass* a, testclass* b, testclass* c){
NewTest();
if (!(cmp(a,b)<0) && !(cmp(b,c)<0) && (cmp(a,c)<0))
4/0;
}

void test2(testclass* a, testclass* b, testclass* c){
NewTest();
if ((cmp(a,b)<0) && (cmp(b,c)<0) && (cmp(c,a)<0)) 
3/0;
}

void test3_1(testclass* a, testclass* b){
NewTest();
if ((cmp(a,b)>0)&&(cmp(b,a)>0))
2/0;
}

void test3_2(testclass* a, testclass* b){
NewTest();
if ((cmp(a,b)<0)&&(cmp(b,a)<0))
2/0;
}

void test4(testclass* a){
NewTest();
if (cmp(a, a)<0||cmp(a, a)>0) 
1/0;
}