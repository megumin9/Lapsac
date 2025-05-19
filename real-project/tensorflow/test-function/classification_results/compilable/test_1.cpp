#include <bits/stdc++.h>
using namespace std;

struct Keypoint {
    int score_;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int KeypointCompare(const void* const a, const void* const b) {
  return (reinterpret_cast<const Keypoint*>(a)->score_ -
          reinterpret_cast<const Keypoint*>(b)->score_) <= 0 ? 1 : -1;
}

void test1(const Keypoint* a, const Keypoint* b, const Keypoint* c){
NewTest();
if (!(KeypointCompare(a,b)<0) && !(KeypointCompare(b,c)<0) && (KeypointCompare(a,c)<0)) 
ConsistencyChecker();
}

void test2(const Keypoint* a, const Keypoint* b, const Keypoint* c){
NewTest();
if ((KeypointCompare(a,b)<0) && (KeypointCompare(b,c)<0) && (KeypointCompare(c,a)<0)) 
TransiveChecker();
}

void test3_1(const Keypoint* a, const Keypoint* b){
NewTest();
if ((KeypointCompare(a,b)<0)&&(KeypointCompare(b,a)<0))
SymmetryChecker();
}

void test3_2(const Keypoint* a, const Keypoint* b){
NewTest();
if ((KeypointCompare(a,b)>0)&&(KeypointCompare(b,a)>0))
SymmetryChecker();
}

void test4(const Keypoint* a){
NewTest();
if (KeypointCompare(a,a)<0||KeypointCompare(a,a)>0) 
ReflexivityChecker();
}