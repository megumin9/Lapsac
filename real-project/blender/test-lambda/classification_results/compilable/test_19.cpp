#include <bits/stdc++.h>
struct CurvePairs {
    std::vector<int> from_frames;
    std::vector<int> to_frames;
} curve_pairs;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const int a, const int b) {
    const int from_frame_a = curve_pairs.from_frames[a];
    const int to_frame_a = curve_pairs.to_frames[a];
    const int from_frame_b = curve_pairs.from_frames[b];
    const int to_frame_b = curve_pairs.to_frames[b];
    return from_frame_a < from_frame_b ||
           (from_frame_a == from_frame_b && to_frame_a < to_frame_b);
}

void test1(int a, int b, int c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(int a, int b, int c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(int a, int b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(int a, int b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(int a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}