#include <bits/stdc++.h>
#include <cstring>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_by_name(const void * arg1, const void * arg2) {
  const char * name1 = *(const char **)arg1;
  const char * name2 = *(const char **)arg2;
  
  int sign = strcmp(name1,name2);
  if (sign != 0) {
    sign = ((name1[0]=='C' && name1[1]=='S') - (name2[0]=='C' && name2[1]=='S'))
           * 4 + (sign >= 0 ? 1 : -1);
  }
  return sign;
}

void test1(const void* a, const void* b, const void* c){
NewTest();
if (!(compare_by_name(a,b)<0) && !(compare_by_name(b,c)<0) && (compare_by_name(a,c)<0))
ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
NewTest();
if ((compare_by_name(a,b)<0) && (compare_by_name(b,c)<0) && (compare_by_name(c,a)<0)) 
TransiveChecker();
}

void test3_1(const void* a, const void* b){
NewTest();
if ((compare_by_name(a,b)>0)&&(compare_by_name(b,a)>0))
SymmetryChecker();
}

void test3_2(const void* a, const void* b){
NewTest();
if ((compare_by_name(a,b)<0)&&(compare_by_name(b,a)<0))
SymmetryChecker();
}

void test4(const void* a){
NewTest();
if (compare_by_name(a, a)<0||compare_by_name(a, a)>0) 
ReflexivityChecker();
}