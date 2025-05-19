#include <bits/stdc++.h>
using namespace std;

namespace data_dictionary {
struct id_type {
    int uuid() const;
};

struct schema_type {
    id_type id() const;
};

struct table {
    const schema_type* schema() const;
};
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const data_dictionary::table& t1, const data_dictionary::table& t2) {
    return t1.schema()->id().uuid() < t2.schema()->id().uuid();
}

void test1(const data_dictionary::table& a, const data_dictionary::table& b, const data_dictionary::table& c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
ConsistencyChecker();
}

void test2(const data_dictionary::table& a, const data_dictionary::table& b, const data_dictionary::table& c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
TransiveChecker();
}

void test3_1(const data_dictionary::table& a, const data_dictionary::table& b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(const data_dictionary::table& a, const data_dictionary::table& b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(const data_dictionary::table& a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}