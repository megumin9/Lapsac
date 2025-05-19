#include <bits/stdc++.h>

struct TimeUUID {};
struct bytes_opt {
    const TimeUUID& operator*() const { static TimeUUID t; return t; }
};

class TimeUUIDType {
public:
    std::function<bool(const TimeUUID&, const TimeUUID&)> as_less_comparator() const;
};

TimeUUIDType* timeuuid_type;
int time_index;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::vector<bytes_opt>& a, const std::vector<bytes_opt>& b) {
    return timeuuid_type->as_less_comparator()(*a[time_index], *b[time_index]);
}

void test1(const std::vector<bytes_opt>& a, const std::vector<bytes_opt>& b, const std::vector<bytes_opt>& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
        ConsistencyChecker();
}

void test2(const std::vector<bytes_opt>& a, const std::vector<bytes_opt>& b, const std::vector<bytes_opt>& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
        TransiveChecker();
}

void test3_1(const std::vector<bytes_opt>& a, const std::vector<bytes_opt>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) 
        SymmetryChecker();
}

void test3_2(const std::vector<bytes_opt>& a, const std::vector<bytes_opt>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a)) 
        SymmetryChecker();
}

void test4(const std::vector<bytes_opt>& a) {
    NewTest();
    if (lambda0(a, a)) 
        ReflexivityChecker();
}