#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct testclass {
    char* var4;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int cmp(testclass *a, testclass *b) {
  int x = strlen(a->var4);
  int y = strlen(b->var4);
  
  return x < y ? 1 : -1;
}

void test1(testclass *a,testclass *b,testclass *c){
NewTest();
if (!(cmp(a,b)<0) && !(cmp(b,c)<0) && (cmp(a,c)<0))
4/0;
}

void test2(testclass *a,testclass *b,testclass *c){
NewTest();
if ((cmp(a,b)<0) && (cmp(b,c)<0) && (cmp(c,a)<0))
3/0;
}

void test3_1(testclass *a,testclass *b){
NewTest();
if ((cmp(a,b)>0)&&(cmp(b,a)>0))
2/0;
}

void test3_2(testclass *a,testclass *b){
NewTest();
if ((cmp(a,b)<0)&&(cmp(b,a)<0))
2/0;
}

void test4(testclass *a){
NewTest();
if (cmp(a, a)<0||cmp(a, a)>0) 
1/0;
}