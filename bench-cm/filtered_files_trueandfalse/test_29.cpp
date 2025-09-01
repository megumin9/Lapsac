#include <bits/stdc++.h>
using namespace std;

struct SharedTerm {
    vector<int> clozeBody;
    vector<int> expression;
    vector<int> conjugationExplanation;
    int score;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_6(const SharedTerm* lhs, const SharedTerm* rhs) {
    if (lhs->clozeBody.size() != rhs->clozeBody.size())
    {
        return lhs->clozeBody.size() > rhs->clozeBody.size();
    }
    if (lhs->expression.size() != rhs->expression.size())
    {
        return lhs->expression.size() > rhs->expression.size();
    }
    if (lhs->conjugationExplanation.size() != rhs->conjugationExplanation.size())
    {
        return lhs->conjugationExplanation.empty() || lhs->conjugationExplanation.size() > rhs->conjugationExplanation.size();
    }
    return lhs->score > rhs->score;
}

void test1(const SharedTerm* a, const SharedTerm* b, const SharedTerm* c){
    NewTest();
    if (!compare_6(a,b) && !compare_6(b,c) && compare_6(a,c)) 
        ConsistencyChecker();
}

void test2(const SharedTerm* a, const SharedTerm* b, const SharedTerm* c){
    NewTest();
    if (compare_6(a,b) && compare_6(b,c) && compare_6(c,a)) 
        TransiveChecker();
}

void test3_1(const SharedTerm* a, const SharedTerm* b){
    NewTest();
    if (compare_6(a,b) && compare_6(b,a))
        SymmetryChecker();
}

void test3_2(const SharedTerm* a, const SharedTerm* b){
    NewTest();
    if (compare_6(a,b) && compare_6(b,a))
        SymmetryChecker();
}

void test4(const SharedTerm* a){
    NewTest();
    if (compare_6(a, a))
        ReflexivityChecker();
}