
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x() const;
};

struct TextCharacter {
    Point position;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const TextCharacter& l, const TextCharacter& r) {
    return l.position.x() < r.position.x();
}

void test1(TextCharacter a, TextCharacter b, TextCharacter c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(TextCharacter a, TextCharacter b, TextCharacter c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(TextCharacter a, TextCharacter b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(TextCharacter a, TextCharacter b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(TextCharacter a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}
