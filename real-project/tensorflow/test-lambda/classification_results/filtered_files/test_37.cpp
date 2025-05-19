#include <bits/stdc++.h>
#include <string>

struct Device {
    std::string name() const;
};

struct CollGroupMember {
    Device device;
};

namespace DeviceNameUtils {
    bool CompareFullNames(const std::string& a, const std::string& b);
}

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const CollGroupMember& lhs, const CollGroupMember& rhs) {
  return DeviceNameUtils::CompareFullNames(lhs.device.name(),
                                                       rhs.device.name());
}

void test1(const CollGroupMember& a, const CollGroupMember& b, const CollGroupMember& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(const CollGroupMember& a, const CollGroupMember& b, const CollGroupMember& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
    TransiveChecker();
}

void test3_1(const CollGroupMember& a, const CollGroupMember& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const CollGroupMember& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}