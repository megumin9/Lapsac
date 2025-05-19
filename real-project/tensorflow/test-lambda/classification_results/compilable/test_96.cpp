#include <bits/stdc++.h>

struct Data {
    long end_timestamp_usec() const;
    long start_timestamp_usec() const;
};

extern std::map<std::string, std::vector<Data>> group_by_pass_name;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const std::string& a, const std::string& b) {
    const Data& a_data = group_by_pass_name[a][0];
    const Data& b_data = group_by_pass_name[b][0];
    return a_data.end_timestamp_usec() - a_data.start_timestamp_usec() >
           b_data.end_timestamp_usec() - b_data.start_timestamp_usec();
}

void test1(const std::string& a, const std::string& b, const std::string& c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
        ConsistencyChecker();
}

void test2(const std::string& a, const std::string& b, const std::string& c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(const std::string& a, const std::string& b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(const std::string& a){
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}