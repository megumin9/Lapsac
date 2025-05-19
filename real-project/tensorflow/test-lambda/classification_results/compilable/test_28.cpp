#include <bits/stdc++.h>
using namespace std;

struct ParsedName {
    int task;
};

class Device {
public:
    ParsedName parsed_name();
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(Device* i, Device* j) {
  ParsedName i_name = i->parsed_name();
  ParsedName j_name = j->parsed_name();
  return i_name.task < j_name.task;
}

void test1(Device* a, Device* b, Device* c){
NewTest();
if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
ConsistencyChecker();
}

void test2(Device* a, Device* b, Device* c){
NewTest();
if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
TransiveChecker();
}

void test3_1(Device* a, Device* b){
NewTest();
if (lambda1(a,b) && lambda1(b,a))
SymmetryChecker();
}

void test3_2(Device* a, Device* b){
NewTest();
if (lambda1(a,b) && lambda1(b,a))
SymmetryChecker();
}

void test4(Device* a){
NewTest();
if (lambda1(a, a))
ReflexivityChecker();
}