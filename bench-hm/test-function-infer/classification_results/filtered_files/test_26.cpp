#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct testclass {
    int var1;
    bool var5;
    char* var4;
};

bool cmp(testclass *a, testclass *b) {
  int x = strlen(a->var4);
  int y = strlen(b->var4);
  
  if (a->var5 && b->var5) 
    return x < y;
  
  return a->var1 < b->var1;
}

void test1(testclass *a, testclass *b, testclass *c){
NewTest();
if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
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

void test3_1(testclass *a, testclass *b){
NewTest();
if (cmp(a,b) && cmp(b,a))
{
int* ptr2 = nullptr;
*ptr2 = 0;
}
}

void test3_2(testclass *a, testclass *b){
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