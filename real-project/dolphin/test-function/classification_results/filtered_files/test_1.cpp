#include <bits/stdc++.h>
using namespace std;

struct nalias {
    int encoding_index;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_by_index(const void * arg1, const void * arg2) {
  const struct nalias * alias1 = (const struct nalias *) arg1;
  const struct nalias * alias2 = (const struct nalias *) arg2;
  return alias1->encoding_index - alias2->encoding_index;
}

void test1(struct nalias* a, struct nalias* b, struct nalias* c) {
NewTest();
if (!(compare_by_index(a,b)<0) && !(compare_by_index(b,c)<0) && (compare_by_index(a,c)<0))
ConsistencyChecker();
}

void test2(struct nalias* a, struct nalias* b, struct nalias* c) {
NewTest();
if ((compare_by_index(a,b)<0) && (compare_by_index(b,c)<0) && (compare_by_index(c,a)<0))
TransiveChecker();
}

void test3_2(struct nalias* a, struct nalias* b) {
NewTest();
if ((compare_by_index(a,b)<0)&&(compare_by_index(b,a)<0))
SymmetryChecker();
}

void test4(struct nalias* a) {
NewTest();
if (compare_by_index(a, a)<0||compare_by_index(a, a)>0) 
ReflexivityChecker();
}