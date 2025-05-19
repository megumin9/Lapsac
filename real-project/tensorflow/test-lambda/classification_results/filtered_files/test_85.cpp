#include <bits/stdc++.h>

struct Shape;
struct HloInstruction {
    const Shape& shape() const;
};
int64_t ShapeSizeInBytes(const Shape&);

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const HloInstruction* inst0, const HloInstruction* inst1) {
  return ShapeSizeInBytes(inst0->shape()) > ShapeSizeInBytes(inst1->shape());
}

void test1(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c) {
  NewTest();
  if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const HloInstruction* a, const HloInstruction* b, const HloInstruction* c) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const HloInstruction* a, const HloInstruction* b) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(const HloInstruction* a, const HloInstruction* b) {
  NewTest();
  if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const HloInstruction* a) {
  NewTest();
  if (lambda1(a, a))
    ReflexivityChecker();
}