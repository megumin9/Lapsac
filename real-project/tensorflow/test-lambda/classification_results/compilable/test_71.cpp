#include <bits/stdc++.h>
using namespace std;

class Flag {
public:
    int GetFlagType() const;
};

extern Flag flag_list[];
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(int a, int b) {
  return flag_list[a].GetFlagType() < flag_list[b].GetFlagType();
}

void test1(int a, int b, int c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
ConsistencyChecker();
}

void test2(int a, int b, int c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
TransiveChecker();
}

void test3_1(int a, int b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(int a, int b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(int a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}