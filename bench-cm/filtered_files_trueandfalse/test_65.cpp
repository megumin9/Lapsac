
#include <bits/stdc++.h>

struct Range {
    int compare(const Range&) const;
};

struct Stmt {
    Range getRange() const;
};

struct File {
    std::string getName() const;
};

struct BlockScope {
    Stmt* getStmt() const;
    File* getContainingFile() const;
};

using BlockScopePtr = std::shared_ptr<BlockScope>;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_12(const BlockScopePtr &b1, const BlockScopePtr &b2) {
    if (auto d = b1->getStmt()->getRange().compare(b2->getStmt()->getRange())) {
        return d < 0; 
    }
    return b1->getContainingFile()->getName() < b2->getContainingFile()->getName();
}

void test1(const BlockScopePtr &a, const BlockScopePtr &b, const BlockScopePtr &c){
    NewTest();
    if (!compare_12(a,b) && !compare_12(b,c) && compare_12(a,c)) 
        ConsistencyChecker();
}

void test2(const BlockScopePtr &a, const BlockScopePtr &b, const BlockScopePtr &c){
    NewTest();
    if (compare_12(a,b) && compare_12(b,c) && compare_12(c,a)) 
        TransiveChecker();
}

void test3_1(const BlockScopePtr &a, const BlockScopePtr &b){
    NewTest();
    if (compare_12(a,b) && compare_12(b,a))
        SymmetryChecker();
}

void test3_2(const BlockScopePtr &a, const BlockScopePtr &b){
    NewTest();
    if (compare_12(a,b) && compare_12(b,a))
        SymmetryChecker();
}

void test4(const BlockScopePtr &a){
    NewTest();
    if (compare_12(a, a))
        ReflexivityChecker();
}
