#include <bits/stdc++.h>
#include <string_view>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int Compare(const std::string_view a, const std::string_view b) {
  return a.compare(b);
}

void test1(std::string_view a, std::string_view b, std::string_view c){
  NewTest();
  if (!(Compare(a,b)<0) && !(Compare(b,c)<0) && (Compare(a,c)<0))
    ConsistencyChecker();
}

void test2(std::string_view a, std::string_view b, std::string_view c){
  NewTest();
  if ((Compare(a,b)<0) && (Compare(b,c)<0) && (Compare(c,a)<0))
    TransiveChecker();
}

void test3_1(std::string_view a, std::string_view b){
  NewTest();
  if ((Compare(a,b)>0)&&(Compare(b,a)>0))
    SymmetryChecker();
}

void test3_2(std::string_view a, std::string_view b){
  NewTest();
  if ((Compare(a,b)<0)&&(Compare(b,a)<0))
    SymmetryChecker();
}

void test4(std::string_view a){
  NewTest();
  if (Compare(a, a)<0||Compare(a, a)>0) 
    ReflexivityChecker();
}