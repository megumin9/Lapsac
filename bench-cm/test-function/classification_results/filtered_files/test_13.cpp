#include <bits/stdc++.h>

struct SiPixelCluster {
    int geographicalId() const;
    int minPixelRow() const;
    int minPixelCol() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_29(const SiPixelCluster& one, const SiPixelCluster& other) {
    if (one.geographicalId() < other.geographicalId()) {
        return true;
    } else if (one.geographicalId() > other.geographicalId()) {
        return false;
    } else if (one.minPixelRow() < other.minPixelRow()) {
        return true;
    } else if (one.minPixelRow() > other.minPixelRow()) {
        return false;
    } else if (one.minPixelCol() <= other.minPixelCol()) {
        return true;
    } else {
        return false;
    }
}

void test1(const SiPixelCluster& a, const SiPixelCluster& b, const SiPixelCluster& c){
    NewTest();
    if (!compare_29(a,b) && !compare_29(b,c) && compare_29(a,c)) 
        ConsistencyChecker();
}

void test2(const SiPixelCluster& a, const SiPixelCluster& b, const SiPixelCluster& c){
    NewTest();
    if (compare_29(a,b) && compare_29(b,c) && compare_29(c,a)) 
        TransiveChecker();
}

void test3_1(const SiPixelCluster& a, const SiPixelCluster& b){
    NewTest();
    if (compare_29(a,b) && compare_29(b,a))
        SymmetryChecker();
}

void test3_2(const SiPixelCluster& a, const SiPixelCluster& b){
    NewTest();
    if (compare_29(a,b) && compare_29(b,a))
        SymmetryChecker();
}

void test4(const SiPixelCluster& a){
    NewTest();
    if (compare_29(a, a)) 
        ReflexivityChecker();
}