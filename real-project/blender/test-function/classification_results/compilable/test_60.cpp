#include <bits/stdc++.h>
using namespace std;

struct Node { int prio; };
extern Node nodes[];
bool comp(int, int);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool custom_less(int id, int jd) {
    return comp(nodes[id].prio, nodes[jd].prio);
}

void test1(int a, int b, int c){
    NewTest();
    if (!custom_less(a,b) && !custom_less(b,c) && custom_less(a,c)) 
        ConsistencyChecker();
}

void test2(int a, int b, int c){
    NewTest();
    if (custom_less(a,b) && custom_less(b,c) && custom_less(c,a)) 
        TransiveChecker();
}

void test3_1(int a, int b){
    NewTest();
    if (custom_less(a,b) && custom_less(b,a))
        SymmetryChecker();
}

void test4(int a){
    NewTest();
    if (custom_less(a, a)) 
        ReflexivityChecker();
}