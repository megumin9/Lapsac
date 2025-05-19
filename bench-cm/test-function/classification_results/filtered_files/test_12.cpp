
#include <bits/stdc++.h>
using namespace std;

struct Olap_Info_t {
    int b_iid;
    int a_iid;
    bool innie;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_32(Olap_Info_t const &a, Olap_Info_t const &b) {
    if (a.b_iid < b.b_iid)      return true;
    if (a.b_iid > b.b_iid)      return false;
    if (a.a_iid < b.a_iid)      return true;
    if (a.a_iid > b.a_iid)      return false;
    return a.innie != b.innie;
}

void test1(Olap_Info_t const &a, Olap_Info_t const &b, Olap_Info_t const &c){
    NewTest();
    if (!compare_32(a,b) && !compare_32(b,c) && compare_32(a,c)) 
        ConsistencyChecker();
}

void test2(Olap_Info_t const &a, Olap_Info_t const &b, Olap_Info_t const &c){
    NewTest();
    if (compare_32(a,b) && compare_32(b,c) && compare_32(c,a)) 
        TransiveChecker();
}

void test3_1(Olap_Info_t const &a, Olap_Info_t const &b){
    NewTest();
    if (compare_32(a,b) && compare_32(b,a))
        SymmetryChecker();
}

void test3_2(Olap_Info_t const &a, Olap_Info_t const &b){
    NewTest();
    if (compare_32(a,b) && compare_32(b,a))
        SymmetryChecker();
}

void test4(Olap_Info_t const &a){
    NewTest();
    if (compare_32(a, a)) 
        ReflexivityChecker();
}
