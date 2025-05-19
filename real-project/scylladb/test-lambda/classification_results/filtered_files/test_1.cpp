#include <bits/stdc++.h>

namespace ss {
struct table_sstables {
    int keyspace() const;
    int table() const;
};
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const ss::table_sstables& t1, const ss::table_sstables& t2) {
    return t1.keyspace() < t2.keyspace() || (t1.keyspace() == t2.keyspace() && t1.table() < t2.table());
}

void test1(const ss::table_sstables& a, const ss::table_sstables& b, const ss::table_sstables& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const ss::table_sstables& a, const ss::table_sstables& b, const ss::table_sstables& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const ss::table_sstables& a, const ss::table_sstables& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(const ss::table_sstables& a, const ss::table_sstables& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const ss::table_sstables& a){
    NewTest();
    if (lambda0(a, a)) 
        ReflexivityChecker();
}