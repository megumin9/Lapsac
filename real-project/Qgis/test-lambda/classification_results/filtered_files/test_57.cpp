
#include <bits/stdc++.h>

struct QgsTextFormat {
    struct Tab {
        int pos;
        int position() const { return pos; }
        Tab(int p) : pos(p) {}
    };
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsTextFormat::Tab &a, const QgsTextFormat::Tab &b) {
  return a.position() < b.position();
}

void test1(QgsTextFormat::Tab a, QgsTextFormat::Tab b, QgsTextFormat::Tab c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(QgsTextFormat::Tab a, QgsTextFormat::Tab b, QgsTextFormat::Tab c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(QgsTextFormat::Tab a, QgsTextFormat::Tab b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(QgsTextFormat::Tab a, QgsTextFormat::Tab b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(QgsTextFormat::Tab a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}
