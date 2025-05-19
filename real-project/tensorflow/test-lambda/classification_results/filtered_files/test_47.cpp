#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct absl {
    struct string_view {
        char back() const;
        size_t size() const;
        bool operator<(const string_view&) const;
    };
};

bool lambda0(absl::string_view a, absl::string_view b) {
  return std::make_tuple(isdigit(a.back()), a.size(), a) < 
         std::make_tuple(isdigit(b.back()), b.size(), b);
}

void test1(absl::string_view a, absl::string_view b, absl::string_view c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
ConsistencyChecker();
}

void test2(absl::string_view a, absl::string_view b, absl::string_view c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
TransiveChecker();
}

void test3_1(absl::string_view a, absl::string_view b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(absl::string_view a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}