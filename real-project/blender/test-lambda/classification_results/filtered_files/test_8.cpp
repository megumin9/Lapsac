#include <bits/stdc++.h>

struct NodeWarning {
    int type;
    std::string message;
};

int node_warning_type_severity(int);
extern "C" int BLI_strcasecmp_natural(const char*, const char*);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const NodeWarning *a, const NodeWarning *b) {
    const int severity_a = node_warning_type_severity(a->type);
    const int severity_b = node_warning_type_severity(b->type);
    if (severity_a > severity_b) return true;
    if (severity_a < severity_b) return false;
    return BLI_strcasecmp_natural(a->message.c_str(), b->message.c_str()) < 0;
}

void test1(const NodeWarning *a, const NodeWarning *b, const NodeWarning *c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const NodeWarning *a, const NodeWarning *b, const NodeWarning *c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const NodeWarning *a, const NodeWarning *b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const NodeWarning *a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}