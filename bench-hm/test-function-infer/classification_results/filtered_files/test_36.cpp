#include <bits/stdc++.h>
#include <cstring>

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
  
  if (x < y)
    return true;
  
  if (a->var1 < b->var1)
    return true;
  
  return false;
}

void test1(testclass *a, testclass *b, testclass *c){
NewTest();
if (!cmp(a,b) &&!cmp(b,c) && cmp(a,c)) 
{
int* ptr4 = nullptr;
*ptr4 = 0;
}
}

void test2(testclass *a, testclass *b, testclass *c){
NewTest();
if (cmp(a,b) && cmp(b,c) && cmp(c,a)) 
{
int* ptr3 = nullptr;
*ptr3 = 0;
}
}

void test3_1(testclass *a,testclass *b){
NewTest();
if (cmp(a,b) && cmp(b,a))
{
int* ptr2 = nullptr;
*ptr2 = 0;
}
}

void test3_2(testclass *a,testclass *b){
NewTest();
if (cmp(a,b) && cmp(b,a))
{
int* ptr2 = nullptr;
*ptr2 = 0;
}
}

void test4(testclass *a){
NewTest();
if (cmp(a, a))
{
int* ptr1 = nullptr;
*ptr1 = 0;
}
}