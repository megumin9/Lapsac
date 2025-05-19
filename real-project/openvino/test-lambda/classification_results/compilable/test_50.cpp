#include <bits/stdc++.h>

struct OutputToPatrition {
    int begin;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(OutputToPatrition lhs, OutputToPatrition rhs) {
    return lhs.begin < rhs.begin;
}

void test1(OutputToPatrition a, OutputToPatrition b, OutputToPatrition c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(OutputToPatrition a, OutputToPatrition b, OutputToPatrition c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(OutputToPatrition a, OutputToPatrition b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(OutputToPatrition a, OutputToPatrition b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(OutputToPatrition a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}