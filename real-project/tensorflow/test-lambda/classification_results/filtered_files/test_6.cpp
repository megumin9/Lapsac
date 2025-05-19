#include <bits/stdc++.h>
using namespace std;

class Device {
public:
    string name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(Device* a, Device* b) {
  return a->name().compare(b->name()) < 0;
}

void test1(Device* a, Device* b, Device* c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(Device* a, Device* b, Device* c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(Device* a, Device* b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(Device* a, Device* b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(Device* a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}