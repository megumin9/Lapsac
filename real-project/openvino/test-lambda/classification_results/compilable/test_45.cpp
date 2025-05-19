#include <bits/stdc++.h>

struct OperatorSetIdProto {
    int version() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const OperatorSetIdProto& lhs, const OperatorSetIdProto& rhs) {
    return lhs.version() > rhs.version();
}

void test1(const OperatorSetIdProto& a, const OperatorSetIdProto& b, const OperatorSetIdProto& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const OperatorSetIdProto& a, const OperatorSetIdProto& b, const OperatorSetIdProto& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const OperatorSetIdProto& a, const OperatorSetIdProto& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(const OperatorSetIdProto& a, const OperatorSetIdProto& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();            
}

void test4(const OperatorSetIdProto& a) {
    NewTest();
    if (lambda0(a, a)) 
        ReflexivityChecker();
}