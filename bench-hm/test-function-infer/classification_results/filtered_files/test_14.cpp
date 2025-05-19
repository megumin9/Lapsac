#include <bits/stdc++.h>
using namespace std;

struct testclass {
    int var5;
    int var1;
    int var2;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int cmp(testclass *a, testclass *b) {
  if (a->var5)
    return 1;

  if (b->var5)
    return -1;

  return a->var1 - b->var2;
}

void test1(testclass* a,testclass* b,testclass* c){
NewTest();
if (!(cmp(a,b)<0) && !(cmp(b,c)<0) && (cmp(a,c)<0))
{
int* ptr4 = nullptr;
*ptr4 = 0;
}
}

void test2(testclass* a,testclass* b,testclass* c){
NewTest();
if ((cmp(a,b)<0) && (cmp(b,c)<0) && (cmp(c,a)<0)) 
{
int* ptr3 = nullptr;
*ptr3 = 0;
}
}

void test3_1(testclass* a,testclass* b){
NewTest();
if ((cmp(a,b)>0)&&(cmp(b,a)>0))
{
int* ptr2 = nullptr;
*ptr2 = 0;
}
}

void test3_2(testclass* a,testclass* b){
NewTest();
if ((cmp(a,b)<0)&&(cmp(b,a)<0))
{
int* ptr2 = nullptr;
*ptr2 = 0;
}
}

void test4(testclass* a){
NewTest();
if (cmp(a, a)<0||cmp(a, a)>0) 
{
int* ptr1 = nullptr;
*ptr1 = 0;
}
}