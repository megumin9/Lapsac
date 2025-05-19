#include <bits/stdc++.h>

struct RocmTracerEvent {
    int start_time_ns;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const RocmTracerEvent& event1, const RocmTracerEvent& event2) {
    return event1.start_time_ns < event2.start_time_ns;
}

void test1(RocmTracerEvent a, RocmTracerEvent b, RocmTracerEvent c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(RocmTracerEvent a, RocmTracerEvent b, RocmTracerEvent c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(RocmTracerEvent a, RocmTracerEvent b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(RocmTracerEvent a, RocmTracerEvent b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(RocmTracerEvent a){
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}