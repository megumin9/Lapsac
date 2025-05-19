#include <bits/stdc++.h>
#include <utility>

namespace nb {
struct handle {};
bool operator<(const handle&, const handle&) { return false; }
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<nb::handle, nb::handle>& a,
             const std::pair<nb::handle, nb::handle>& b) {
  return a.first < b.first;
}

void test1(const std::pair<nb::handle, nb::handle>& a, const std::pair<nb::handle, nb::handle>& b, const std::pair<nb::handle, nb::handle>& c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
ConsistencyChecker();
}

void test2(const std::pair<nb::handle, nb::handle>& a, const std::pair<nb::handle, nb::handle>& b, const std::pair<nb::handle, nb::handle>& c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
TransiveChecker();
}

void test3_1(const std::pair<nb::handle, nb::handle>& a, const std::pair<nb::handle, nb::handle>& b){
NewTest();
if (lambda0(a,b) && lambda0(b,a)) 
SymmetryChecker();
}

void test3_2(const std::pair<nb::handle, nb::handle>& a, const std::pair<nb::handle, nb::handle>& b){
NewTest();
if (lambda0(a,b) && lambda0(b,a)) 
SymmetryChecker();
}

void test4(const std::pair<nb::handle, nb::handle>& a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}