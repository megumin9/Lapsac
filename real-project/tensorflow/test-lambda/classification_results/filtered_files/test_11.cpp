#include <bits/stdc++.h>
using namespace std;

struct WordFreq {
    int second;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const WordFreq& x, const WordFreq& y) { return x.second > y.second; }

void test1(WordFreq a, WordFreq b, WordFreq c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(WordFreq a, WordFreq b, WordFreq c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(WordFreq a, WordFreq b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(WordFreq a, WordFreq b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(WordFreq a){
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}