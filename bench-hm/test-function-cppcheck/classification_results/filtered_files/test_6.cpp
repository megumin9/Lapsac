#include <cstring>

struct testclass {
    char* var4;
    bool var5;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmp(testclass *a, testclass *b) {
  int x = strlen(a->var4);
  int y = strlen(b->var4);
  
  if (a->var5 && b->var5) 
    return x < y;
  
  return false;
}

void test1(testclass *a, testclass *b, testclass *c){
NewTest();
if (!cmp(a,b) && !cmp(b,c) && cmp(a,c))
4/0;
}

void test2(testclass *a, testclass *b, testclass *c){
NewTest();
if (cmp(a,b) && cmp(b,c) && cmp(c,a))
3/0;
}

void test3_1(testclass *a, testclass *b){
NewTest();
if (cmp(a,b) && cmp(b,a))
2/0;
}

void test3_2(testclass *a, testclass *b){
NewTest();
if (cmp(a,b) && cmp(b,a))
2/0;
}

void test4(testclass *a){
NewTest();
if (cmp(a, a))
1/0;
}