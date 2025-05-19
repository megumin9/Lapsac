#include <bits/stdc++.h>

enum class ChallengeRank { Digest };
struct AuthChallenge {
    ChallengeRank rank;
    int algorithm;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_3(const AuthChallenge& lhs, const AuthChallenge& rhs) {
  if (lhs.rank != rhs.rank) {
    return lhs.rank < rhs.rank ? 1 : -1;
  }

  if (lhs.rank != ChallengeRank::Digest) {
    return 0;
  }

  if (lhs.algorithm == 0 || rhs.algorithm == 0) {
    return 0;
  }

  return lhs.algorithm < rhs.algorithm ? 1 : -1;
}

void test1(AuthChallenge a, AuthChallenge b, AuthChallenge c){
NewTest();
if (!(compare_3(a,b)<0) && !(compare_3(b,c)<0) && (compare_3(a,c)<0)) 
ConsistencyChecker();
}

void test2(AuthChallenge a, AuthChallenge b, AuthChallenge c){
NewTest();
if ((compare_3(a,b)<0) && (compare_3(b,c)<0) && (compare_3(c,a)<0)) 
TransiveChecker();
}

void test3_1(AuthChallenge a,AuthChallenge b){
NewTest();
if ((compare_3(a,b)>0)&&(compare_3(b,a)>0))
SymmetryChecker();
}

void test3_2(AuthChallenge a,AuthChallenge b){
NewTest();
if ((compare_3(a,b)<0)&&(compare_3(b,a)<0))
SymmetryChecker();
}

void test4(AuthChallenge a){
NewTest();
if (compare_3(a, a)<0||compare_3(a, a)>0) 
ReflexivityChecker();
}