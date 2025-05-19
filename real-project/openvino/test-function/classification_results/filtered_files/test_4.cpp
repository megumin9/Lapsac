#include <bits/stdc++.h>
using namespace std;

namespace ov {
struct IntervalsAlignmentAttribute {
    struct ValueType {
        struct Interval {
            int low;
            int high;
        };
        Interval combinedInterval;
    };
    ValueType value() const { return {}; }
};
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare(const ov::IntervalsAlignmentAttribute& value1, const ov::IntervalsAlignmentAttribute& value2) {
    if ((value1.value().combinedInterval.low != value2.value().combinedInterval.low) ||
        (value1.value().combinedInterval.high != value2.value().combinedInterval.high)) {
        return false;
    }
    return true;
}

void test1(const ov::IntervalsAlignmentAttribute& a, const ov::IntervalsAlignmentAttribute& b, const ov::IntervalsAlignmentAttribute& c) {
    NewTest();
    if (!compare(a, b) && !compare(b, c) && compare(a, c)) {
        ConsistencyChecker();
    }
}

void test2(const ov::IntervalsAlignmentAttribute& a, const ov::IntervalsAlignmentAttribute& b, const ov::IntervalsAlignmentAttribute& c) {
    NewTest();
    if (compare(a, b) && compare(b, c) && compare(c, a)) {
        TransiveChecker();
    }
}

void test3_1(const ov::IntervalsAlignmentAttribute& a, const ov::IntervalsAlignmentAttribute& b) {
    NewTest();
    if (compare(a, b) && compare(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(const ov::IntervalsAlignmentAttribute& a, const ov::IntervalsAlignmentAttribute& b) {
    NewTest();
    if (compare(a, b) && compare(b, a)) {
        SymmetryChecker();
    }
}

void test4(const ov::IntervalsAlignmentAttribute& a) {
    NewTest();
    if (compare(a, a)) {
        ReflexivityChecker();
    }
}