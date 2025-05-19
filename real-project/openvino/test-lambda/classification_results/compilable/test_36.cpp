#include <bits/stdc++.h>
#include <utility>
#include <cstdint>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const std::pair<int64_t, size_t>& first, const std::pair<int64_t, size_t>& second) {
    return first.first > second.first;
}

void test1(const std::pair<int64_t, size_t>& a, const std::pair<int64_t, size_t>& b, const std::pair<int64_t, size_t>& c){
NewTest();
if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
ConsistencyChecker();
}

void test2(const std::pair<int64_t, size_t>& a, const std::pair<int64_t, size_t>& b, const std::pair<int64_t, size_t>& c){
NewTest();
if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
TransiveChecker();
}

void test3_1(const std::pair<int64_t, size_t>& a, const std::pair<int64_t, size_t>& b){
NewTest();
if (lambda1(a,b) && lambda1(b,a))
SymmetryChecker();
}

void test3_2(const std::pair<int64_t, size_t>& a, const std::pair<int64_t, size_t>& b){
NewTest();
if (lambda1(a,b) && lambda1(b,a))
SymmetryChecker();
}

void test4(const std::pair<int64_t, size_t>& a){
NewTest();
if (lambda1(a, a))
ReflexivityChecker();
}