#include <bits/stdc++.h>

struct Bone {
    int id;
};

void ai_assert(bool);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool BoneCompare(Bone *a, Bone *b) {
    ai_assert(nullptr != a);
    ai_assert(nullptr != b);
    return (a->id < b->id);
}

void test1(Bone* a,Bone* b,Bone* c){
    NewTest();
    if (!BoneCompare(a,b) && !BoneCompare(b,c) && BoneCompare(a,c))
    ConsistencyChecker();
}

void test2(Bone* a,Bone* b,Bone* c){
    NewTest();
    if (BoneCompare(a,b) && BoneCompare(b,c) && BoneCompare(c,a))
    TransiveChecker();
}

void test3_1(Bone* a,Bone* b){
    NewTest();
    if (BoneCompare(a,b) && BoneCompare(b,a))
    SymmetryChecker();
}

void test4(Bone* a){
    NewTest();
    if (BoneCompare(a, a))
    ReflexivityChecker();
}