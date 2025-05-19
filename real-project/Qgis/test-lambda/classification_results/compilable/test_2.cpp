#include <bits/stdc++.h>

struct Point {
    int y() const;
};

struct TextCharacter {
    Point position;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const TextCharacter& l, const TextCharacter& r) {
    return l.position.y() < r.position.y();
}

void test1(TextCharacter a, TextCharacter b, TextCharacter c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c)) 
        ConsistencyChecker();
}

void test2(TextCharacter a, TextCharacter b, TextCharacter c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a)) 
        TransiveChecker();
}

void test3_1(TextCharacter a, TextCharacter b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(TextCharacter a, TextCharacter b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(TextCharacter a){
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}