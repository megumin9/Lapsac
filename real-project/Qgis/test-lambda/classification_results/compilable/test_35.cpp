#include <utility>
#include <string>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<std::string, std::string> &pair1, const std::pair<std::string, std::string> &pair2) {
    return ( pair1.first.length() > pair2.first.length() );
}

void test1(const std::pair<std::string, std::string> &a, const std::pair<std::string, std::string> &b, const std::pair<std::string, std::string> &c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const std::pair<std::string, std::string> &a, const std::pair<std::string, std::string> &b, const std::pair<std::string, std::string> &c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const std::pair<std::string, std::string> &a, const std::pair<std::string, std::string> &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const std::pair<std::string, std::string> &a, const std::pair<std::string, std::string> &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const std::pair<std::string, std::string> &a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}