#include <bits/stdc++.h>

extern "C" int strncmp(const char*, const char*, size_t);
extern "C" size_t strlen(const char*);

struct Object {
    struct { const char* name; } id;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_16(const Object* left, const Object* right) {
    return ::strncmp(left->id.name, right->id.name, ::strlen(left->id.name)) == 0;
}

void test1(Object* a, Object* b, Object* c){
    NewTest();
    if (!compare_16(a,b) && !compare_16(b,c) && compare_16(a,c))
        ConsistencyChecker();
}

void test2(Object* a, Object* b, Object* c){
    NewTest();
    if (compare_16(a,b) && compare_16(b,c) && compare_16(c,a))
        TransiveChecker();
}

void test3_1(Object* a, Object* b){
    NewTest();
    if (compare_16(a,b) && compare_16(b,a))
        SymmetryChecker();
}

void test3_2(Object* a, Object* b){
    NewTest();
    if (compare_16(a,b) && compare_16(b,a))
        SymmetryChecker();
}

void test4(Object* a){
    NewTest();
    if (compare_16(a, a))
        ReflexivityChecker();
}