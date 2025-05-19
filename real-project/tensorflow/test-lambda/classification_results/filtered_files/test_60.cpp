#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    const string& name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(Node* a, Node* b) {
  return a->name() < b->name();
}

void test1(Node* a, Node* b, Node* c){
NewTest();
if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c)) 
ConsistencyChecker();
}

void test2(Node* a, Node* b, Node* c){
NewTest();
if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a)) 
TransiveChecker();
}

void test3_1(Node* a, Node* b){
NewTest();
if (lambda1(a,b) && lambda1(b,a))
SymmetryChecker();
}

void test3_2(Node* a, Node* b){
NewTest();
if (lambda1(a,b) && lambda1(b,a))
SymmetryChecker();
}

void test4(Node* a){
NewTest();
if (lambda1(a, a))
ReflexivityChecker();
}