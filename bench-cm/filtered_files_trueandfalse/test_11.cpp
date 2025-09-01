#include <bits/stdc++.h>

enum SHTType { SHT_NOBITS };

class OutputSectionBase {
public:
    SHTType getType() const;
    std::string getName() const;
};

int getPPC64SectionRank(const std::string &);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_36(OutputSectionBase *A, OutputSectionBase *B) {
  if (A->getType() != B->getType())
    return A->getType() != SHT_NOBITS && B->getType() == SHT_NOBITS;
  return getPPC64SectionRank(A->getName()) < getPPC64SectionRank(B->getName());
}

void test1(OutputSectionBase *a, OutputSectionBase *b, OutputSectionBase *c) {
  NewTest();
  if (!compare_36(a,b) && !compare_36(b,c) && compare_36(a,c))
    ConsistencyChecker();
}

void test2(OutputSectionBase *a, OutputSectionBase *b, OutputSectionBase *c) {
  NewTest();
  if (compare_36(a,b) && compare_36(b,c) && compare_36(c,a))
    TransiveChecker();
}

void test3_1(OutputSectionBase *a, OutputSectionBase *b) {
  NewTest();
  if (compare_36(a,b) && compare_36(b,a))
    SymmetryChecker();
}

void test3_2(OutputSectionBase *a, OutputSectionBase *b) {
  NewTest();
  if (compare_36(a,b) && compare_36(b,a))
    SymmetryChecker();
}

void test4(OutputSectionBase *a) {
  NewTest();
  if (compare_36(a, a))
    ReflexivityChecker();
}