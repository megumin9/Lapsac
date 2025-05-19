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

void test1(Image a, Image b, Image c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(Image a, Image b, Image c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(Image a, Image b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(Image a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}