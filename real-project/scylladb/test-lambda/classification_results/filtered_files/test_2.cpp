#include <bits/stdc++.h>

struct data_value {
    std::string serialize_nonnull() const;
};

struct element_type_struct {
    bool less(const std::string&, const std::string&) const;
};
extern element_type_struct* element_type;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const data_value& a, const data_value& b) {
    return element_type->less(a.serialize_nonnull(), b.serialize_nonnull());
}

void test1(const data_value& a, const data_value& b, const data_value& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const data_value& a, const data_value& b, const data_value& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const data_value& a, const data_value& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(const data_value& a, const data_value& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const data_value& a){
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}