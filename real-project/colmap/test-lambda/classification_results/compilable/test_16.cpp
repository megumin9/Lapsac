
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

bool lambda1(const ImageInfo& image_info1, const ImageInfo& image_info2) {
  if (image_info1.prior_focal_length && !image_info2.prior_focal_length) {
    return true;
  } else if (!image_info1.prior_focal_length && image_info2.prior_focal_length) {
    return false;
  } else {
    return image_info1.num_correspondences > image_info2.num_correspondences;
  }
}

void test1(ImageInfo a, ImageInfo b, ImageInfo c){
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(ImageInfo a, ImageInfo b, ImageInfo c){
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(ImageInfo a, ImageInfo b){
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(ImageInfo a, ImageInfo b){
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(ImageInfo a){
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}
