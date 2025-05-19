#include <bits/stdc++.h>

struct cudaDeviceProp {
    int major;
    int minor;
    int multiProcessorCount;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool CompareCudaDevice(const cudaDeviceProp& d1, const cudaDeviceProp& d2) {
  bool result = (d1.major > d2.major) ||
                ((d1.major == d2.major) && (d1.minor > d2.minor)) ||
                ((d1.major == d2.major) && (d1.minor == d2.minor) &&
                 (d1.multiProcessorCount > d2.multiProcessorCount));
  return result;
}

void test1(const cudaDeviceProp& a, const cudaDeviceProp& b, const cudaDeviceProp& c) {
    NewTest();
    if (!CompareCudaDevice(a, b) && !CompareCudaDevice(b, c) && CompareCudaDevice(a, c)) {
        ConsistencyChecker();
    }
}

void test2(const cudaDeviceProp& a, const cudaDeviceProp& b, const cudaDeviceProp& c) {
    NewTest();
    if (CompareCudaDevice(a, b) && CompareCudaDevice(b, c) && CompareCudaDevice(c, a)) {
        TransiveChecker();
    }
}

void test3_1(const cudaDeviceProp& a, const cudaDeviceProp& b) {
    NewTest();
    if (CompareCudaDevice(a, b) && CompareCudaDevice(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(const cudaDeviceProp& a, const cudaDeviceProp& b) {
    NewTest();
    if (CompareCudaDevice(a, b) && CompareCudaDevice(b, a)) {
        SymmetryChecker();
    }
}

void test4(const cudaDeviceProp& a) {
    NewTest();
    if (CompareCudaDevice(a, a)) {
        ReflexivityChecker();
    }
}