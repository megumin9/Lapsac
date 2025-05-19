#include <bits/stdc++.h>
using namespace std;

namespace LoopLevel {
    using KeyValue = pair<int, int>;
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const LoopLevel::KeyValue& a, const LoopLevel::KeyValue& b) {
    return a.first < b.first;
}

void test1(const LoopLevel::KeyValue& a, const LoopLevel::KeyValue& b, const LoopLevel::KeyValue& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const LoopLevel::KeyValue& a, const LoopLevel::KeyValue& b, const LoopLevel::KeyValue& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const LoopLevel::KeyValue& a, const LoopLevel::KeyValue& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const LoopLevel::KeyValue& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}