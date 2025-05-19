#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

template<typename T>
struct FlatTensor {
    size_t size() const;
    T operator()(int) const;
};

struct Tensor {
    template<typename U>
    FlatTensor<U> flat() const;
};

bool compare(const Tensor& t1, const Tensor& t2) {
  FlatTensor<int> flat_t1 = t1.flat<int>();
  FlatTensor<int> flat_t2 = t2.flat<int>();
  size_t length = std::min(flat_t1.size(), flat_t2.size());
  for (int i = 0; i < length; ++i) {
    if (flat_t1(i) < flat_t2(i)) return true;
    if (flat_t1(i) > flat_t2(i)) return false;
  }
  return flat_t1.size() < length;
}

void test1(const Tensor& a, const Tensor& b, const Tensor& c) {
  NewTest();
  if (!compare(a,b) && !compare(b,c) && compare(a,c))
    ConsistencyChecker();
}

void test2(const Tensor& a, const Tensor& b, const Tensor& c) {
  NewTest();
  if (compare(a,b) && compare(b,c) && compare(c,a))
    TransiveChecker();
}

void test3_1(const Tensor& a, const Tensor& b) {
  NewTest();
  if (compare(a,b) && compare(b,a))
    SymmetryChecker();
}

void test4(const Tensor& a) {
  NewTest();
  if (compare(a, a))
    ReflexivityChecker();
}