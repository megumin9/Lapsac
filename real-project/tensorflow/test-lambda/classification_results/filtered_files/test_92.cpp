#include <bits/stdc++.h>
using namespace std;

struct Point {
    int end_timestamp_millis;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Point& a, const Point& b) {
  return a.end_timestamp_millis < b.end_timestamp_millis;
}

void test1(Point a, Point b, Point c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(Point a, Point b, Point c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(Point a, Point b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(Point a, Point b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(Point a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}