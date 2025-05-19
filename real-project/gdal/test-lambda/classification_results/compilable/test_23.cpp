#include <bits/stdc++.h>

typedef std::string CPLString;
bool EQUAL(const char*, const char*);
CPLString CPLGetBasenameSafe(const CPLString&);
CPLString CPLGetExtensionSafe(const CPLString&);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

std::map<const char*, int> oMapLayerOrder;

bool lambda0(const CPLString &a, const CPLString &b) {
    int iA = INT_MAX;
    std::map<const char*, int>::iterator oIterA = oMapLayerOrder.find(CPLGetBasenameSafe(a).c_str());
    if (oIterA != oMapLayerOrder.end())
        iA = oIterA->second;
    int iB = INT_MAX;
    std::map<const char*, int>::iterator oIterB = oMapLayerOrder.find(CPLGetBasenameSafe(b).c_str());
    if (oIterB != oMapLayerOrder.end())
        iB = oIterB->second;
    if (iA < iB)
        return true;
    if (iA > iB)
        return false;
    if (iA != INT_MAX) {
        if (EQUAL(CPLGetExtensionSafe(a).c_str(), "shp"))
            return true;
        if (EQUAL(CPLGetExtensionSafe(b).c_str(), "shp"))
            return false;
    }
    return a < b;
}

void test1(const CPLString &a, const CPLString &b, const CPLString &c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const CPLString &a, const CPLString &b, const CPLString &c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const CPLString &a, const CPLString &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(const CPLString &a, const CPLString &b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const CPLString &a) {
    NewTest();
    if (lambda0(a,a))
        ReflexivityChecker();
}