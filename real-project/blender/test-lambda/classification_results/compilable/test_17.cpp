#include <bits/stdc++.h>
struct Scene;
struct View2D;
struct Strip {};
extern Scene* scene;
extern View2D* v2d;
extern int mouse_co[1];
int strip_to_frame_distance(Scene*, View2D*, const Strip*, int);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const Strip *seq1, const Strip *seq2) {
    return strip_to_frame_distance(scene, v2d, seq1, mouse_co[0]) <
           strip_to_frame_distance(scene, v2d, seq2, mouse_co[0]);
}

void test1(Strip* a, Strip* b, Strip* c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(Strip* a, Strip* b, Strip* c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(Strip* a, Strip* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(Strip* a, Strip* b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(Strip* a) {
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}