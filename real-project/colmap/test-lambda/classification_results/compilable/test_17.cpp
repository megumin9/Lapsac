
#include <bits/stdc++.h>
using namespace std;

struct ImageInfo {
    bool prior_focal_length;
    int num_correspondences;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const ImageInfo& image_info1, const ImageInfo& image_info2) {
  if (image_info1.prior_focal_length && !image_info2.prior_focal_length) {
    return true;
  } else if (!image_info1.prior_focal_length &&
             image_info2.prior_focal_length) {
    return false;
  } else {
    return image_info1.num_correspondences >
           image_info2.num_correspondences;
  }
}

void test1(const ImageInfo& a, const ImageInfo& b, const ImageInfo& c){
  NewTest();
  if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
    ConsistencyChecker();
}

void test2(const ImageInfo& a, const ImageInfo& b, const ImageInfo& c){
  NewTest();
  if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a))
    TransiveChecker();
}

void test3_1(const ImageInfo& a, const ImageInfo& b){
  NewTest();
  if (lambda2(a,b) && lambda2(b,a))
    SymmetryChecker();
}

void test4(const ImageInfo& a){
  NewTest();
  if (lambda2(a, a))
    ReflexivityChecker();
}
