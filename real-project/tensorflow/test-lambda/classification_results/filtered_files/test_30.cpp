#include <bits/stdc++.h>

struct Name {
    int id;
};

class Device {
public:
    Name parsed_name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda3(Device* i, Device* j) {
  return i->parsed_name().id < j->parsed_name().id;
}

void test1(Device* a, Device* b, Device* c){
NewTest();
if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c))
ConsistencyChecker();
}

void test2(Device* a, Device* b, Device* c){
NewTest();
if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a))
TransiveChecker();
}

void test3_1(Device* a, Device* b){
NewTest();
if (lambda3(a,b) && lambda3(b,a))
SymmetryChecker();
}

void test3_2(Device* a, Device* b){
NewTest();
if (lambda3(a,b) && lambda3(b,a))
SymmetryChecker();
}

void test4(Device* a){
NewTest();
if (lambda3(a, a))
ReflexivityChecker();
}