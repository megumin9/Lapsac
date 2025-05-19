#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int qh_intcompare(const void *i, const void *j) {
  return(*((const int *)i) - *((const int *)j));
}

void test1(int a,int b,int c){
NewTest();
if (!(qh_intcompare(&a,&b)<0) && !(qh_intcompare(&b,&c)<0) && (qh_intcompare(&a,&c)<0))
ConsistencyChecker();
}

void test2(int a,int b,int c){
NewTest();
if ((qh_intcompare(&a,&b)<0) && (qh_intcompare(&b,&c)<0) && (qh_intcompare(&c,&a)<0))
TransiveChecker();
}

void test3_1(int a,int b){
NewTest();
if ((qh_intcompare(&a,&b)<0)&&(qh_intcompare(&b,&a)<0))
SymmetryChecker();
}

void test3_2(int a,int b){
NewTest();
if ((qh_intcompare(&a,&b)>0)&&(qh_intcompare(&b,&a)>0))
SymmetryChecker();
}

void test4(int a){
NewTest();
if (qh_intcompare(&a, &a)<0||qh_intcompare(&a, &a)>0) 
ReflexivityChecker();
}