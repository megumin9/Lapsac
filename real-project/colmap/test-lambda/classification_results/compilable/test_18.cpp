#include <bits/stdc++.h>
struct image_t {};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda3(const std::pair<image_t, size_t>& image1,
             const std::pair<image_t, size_t>& image2) {
    return image1.second > image2.second;
}

void test1(const std::pair<image_t, size_t>& a,
           const std::pair<image_t, size_t>& b,
           const std::pair<image_t, size_t>& c) {
    NewTest();
    if (!lambda3(a,b) && !lambda3(b,c) && lambda3(a,c))
        ConsistencyChecker();
}

void test2(const std::pair<image_t, size_t>& a,
           const std::pair<image_t, size_t>& b,
           const std::pair<image_t, size_t>& c) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,c) && lambda3(c,a))
        TransiveChecker();
}

void test3_1(const std::pair<image_t, size_t>& a,
            const std::pair<image_t, size_t>& b) {
    NewTest();
    if (lambda3(a,b) && lambda3(b,a))
        SymmetryChecker();
}

void test4(const std::pair<image_t, size_t>& a) {
    NewTest();
    if (lambda3(a, a))
        ReflexivityChecker();
}