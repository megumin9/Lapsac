#include <bits/stdc++.h>
using namespace std;

class Object {
public:
    bool hasPriority() const;
    int getPriority() const;
    string getClassName() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_38(Object &a, Object &b) {
  if (a.hasPriority() && b.hasPriority()) {
    return a.getPriority() - b.getPriority();
  }
  return a.getClassName().compare(b.getClassName());
}

void test1(Object &a, Object &b, Object &c){
NewTest();
if (!(compare_38(a,b)<0) && !(compare_38(b,c)<0) && (compare_38(a,c)<0))
ConsistencyChecker();
}

void test2(Object &a, Object &b, Object &c){
NewTest();
if ((compare_38(a,b)<0) && (compare_38(b,c)<0) && (compare_38(c,a)<0)) 
TransiveChecker();
}

void test3_1(Object &a, Object &b){
NewTest();
if ((compare_38(a,b)>0)&&(compare_38(b,a)>0))
SymmetryChecker();
}

void test3_2(Object &a, Object &b){
NewTest();
if ((compare_38(a,b)<0)&&(compare_38(b,a)<0))
SymmetryChecker();
}

void test4(Object &a){
NewTest();
if (compare_38(a, a)<0||compare_38(a, a)>0) 
ReflexivityChecker();
}