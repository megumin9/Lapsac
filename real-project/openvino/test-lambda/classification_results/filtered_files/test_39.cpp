#include <bits/stdc++.h>
using namespace std;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

class VariableState {
public:
    string get_name() const;
};

bool lambda0(VariableState& a, VariableState& b) {
    return a.get_name() > b.get_name();
}

void test1(VariableState& a, VariableState& b, VariableState& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(VariableState& a, VariableState& b, VariableState& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(VariableState& a, VariableState& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(VariableState& a, VariableState& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(VariableState& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}