#include <bits/stdc++.h>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

struct EntryType {
    int image_id;
};
bool lambda0(const EntryType& entry1, const EntryType& entry2) {
  return entry1.image_id < entry2.image_id;
}

void test1(EntryType a, EntryType b, EntryType c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(EntryType a, EntryType b, EntryType c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(EntryType a, EntryType b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(EntryType a, EntryType b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(EntryType a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}