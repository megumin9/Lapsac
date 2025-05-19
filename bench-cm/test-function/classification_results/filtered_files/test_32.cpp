
#include <bits/stdc++.h>

struct NullUsage {
    static NullUsage INSTANCE;
};

int compareByFileAndOffset(const void* o1, const void* o2);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_31(const void* o1, const void* o2) {
    if (o1 == o2) return 0;
    if (o1 == &NullUsage::INSTANCE || o1 == nullptr) return -1;
    if (o2 == &NullUsage::INSTANCE || o2 == nullptr) return 1;
    
    int c = compareByFileAndOffset(o1, o2);
    if (c != 0) return c;

    std::string str1 = *static_cast<const std::string*>(o1);
    std::string str2 = *static_cast<const std::string*>(o2);
    return str1.compare(str2);
}

void test1(const void* a, const void* b, const void* c){
    NewTest();
    if (!(compare_31(a,b)<0) && !(compare_31(b,c)<0) && (compare_31(a,c)<0))
        ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
    NewTest();
    if ((compare_31(a,b)<0) && (compare_31(b,c)<0) && (compare_31(c,a)<0))
        TransiveChecker();
}

void test3_1(const void* a, const void* b){
    NewTest();
    if ((compare_31(a,b)>0)&&(compare_31(b,a)>0))
        SymmetryChecker();
}

void test3_2(const void* a, const void* b){
    NewTest();
    if ((compare_31(a,b)<0)&&(compare_31(b,a)<0))
        SymmetryChecker();
}

void test4(const void* a){
    NewTest();
    if (compare_31(a, a)<0 || compare_31(a, a)>0)
        ReflexivityChecker();
}
