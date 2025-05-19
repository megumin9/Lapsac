#include <bits/stdc++.h>
#include <glog/logging.h>
#include <memory>

struct TfDeviceSpec {
    int device_ordinal;
    int index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const TfDeviceSpec& a, const TfDeviceSpec& b) {
  if (a.device_ordinal < b.device_ordinal) {
    return true;
  } else if (a.device_ordinal > b.device_ordinal) {
    return false;
  }
  DCHECK_EQ(a.device_ordinal, b.device_ordinal);
  DCHECK(std::addressof(a) == std::addressof(b) ||
         a.index != b.index);  
  if (a.index < b.index) {
    return true;
  }
  return false;
}

void test1(const TfDeviceSpec& a, const TfDeviceSpec& b, const TfDeviceSpec& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const TfDeviceSpec& a, const TfDeviceSpec& b, const TfDeviceSpec& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const TfDeviceSpec& a, const TfDeviceSpec& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const TfDeviceSpec& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}