#include <bits/stdc++.h>
#include <map>

namespace ov {
using AnyMap = std::map<std::string, int>;
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare(ov::AnyMap a, ov::AnyMap b) {
    if (a.size() != b.size())
        return false;
    for (std::pair<const std::string, int>& it : a) {
        ov::AnyMap::iterator item = b.find(it.first);
        if (item == b.end())
            return false;
        if (it.second != item->second)
            return false;
    }
    return true;
}

void test1(ov::AnyMap a, ov::AnyMap b, ov::AnyMap c) {
    NewTest();
    if (!compare(a, b) && !compare(b, c) && compare(a, c))
        ConsistencyChecker();
}

void test2(ov::AnyMap a, ov::AnyMap b, ov::AnyMap c) {
    NewTest();
    if (compare(a, b) && compare(b, c) && compare(c, a))
        TransiveChecker();
}

void test3_1(ov::AnyMap a, ov::AnyMap b) {
    NewTest();
    if (compare(a, b) && compare(b, a))
        SymmetryChecker();
}

void test3_2(ov::AnyMap a, ov::AnyMap b) {
    NewTest();
    if (compare(a, b) && compare(b, a))
        SymmetryChecker();
}

void test4(ov::AnyMap a) {
    NewTest();
    if (compare(a, a))
        ReflexivityChecker();
}