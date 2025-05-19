#include <bits/stdc++.h>

class CostObject {
public:
    int cost() const;
};

using ParamChecker = std::pair<int, CostObject*>;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(ParamChecker a, ParamChecker b) {
  return a.second->cost() < b.second->cost();
}

void test1(ParamChecker a, ParamChecker b, ParamChecker c){
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(ParamChecker a, ParamChecker b, ParamChecker c){
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(ParamChecker a, ParamChecker b){
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(ParamChecker a, ParamChecker b){
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(ParamChecker a){
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}