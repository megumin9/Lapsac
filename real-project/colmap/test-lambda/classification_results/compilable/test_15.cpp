#include <bits/stdc++.h>

struct image_t {};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<image_t, float>& image1,
             const std::pair<image_t, float>& image2) {
    return image1.second > image2.second;
}

void test1(const std::pair<image_t, float>& a, const std::pair<image_t, float>& b, const std::pair<image_t, float>& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const std::pair<image_t, float>& a, const std::pair<image_t, float>& b, const std::pair<image_t, float>& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const std::pair<image_t, float>& a, const std::pair<image_t, float>& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const std::pair<image_t, float>& a, const std::pair<image_t, float>& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const std::pair<image_t, float>& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}