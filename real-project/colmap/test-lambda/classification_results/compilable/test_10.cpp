
#include <bits/stdc++.h>

struct Cluster {
    std::vector<int> image_ids;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const Cluster& first, const Cluster& second) {
    return first.image_ids.size() >= second.image_ids.size() &&
           *std::min_element(first.image_ids.begin(),
                             first.image_ids.end()) <
               *std::min_element(second.image_ids.begin(),
                                 second.image_ids.end());
}

void test1(Cluster a, Cluster b, Cluster c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
        ConsistencyChecker();
}

void test2(Cluster a, Cluster b, Cluster c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
        TransiveChecker();
}

void test3_1(Cluster a, Cluster b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test3_2(Cluster a, Cluster b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
        SymmetryChecker();
}

void test4(Cluster a){
    NewTest();
    if (lambda1(a, a))
        ReflexivityChecker();
}
