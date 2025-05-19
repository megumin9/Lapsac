#include <bits/stdc++.h>
using namespace std;

class Image {
public:
    string Name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Image& image1, const Image& image2) {
  return image1.Name() < image2.Name();
}

void test1(const Image& a, const Image& b, const Image& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const Image& a, const Image& b, const Image& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const Image& a, const Image& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const Image& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}