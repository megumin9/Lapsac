
#include <bits/stdc++.h>

class FunctionFilter {
public:
    enum FilterType {
        SKIP_TARGET_ANNOTATION
    };
    FilterType filter_type() const;
};

class TacFilter {
public:
    bool has_function_filter() const;
    const FunctionFilter& function_filter() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const TacFilter* a, const TacFilter* b) {
  const bool a_is_function_filter = a->has_function_filter();
  const bool b_is_function_filter = b->has_function_filter();
  if (a_is_function_filter != b_is_function_filter) {
    return a_is_function_filter > b_is_function_filter;
  }

  if (!a_is_function_filter && !b_is_function_filter) {
    return false;
  }

  const bool a_is_function_exclude =
      (a->function_filter().filter_type() == FunctionFilter::SKIP_TARGET_ANNOTATION);
  const bool b_is_function_exclude =
      (b->function_filter().filter_type() == FunctionFilter::SKIP_TARGET_ANNOTATION);
  return a_is_function_exclude > b_is_function_exclude;
}

void test1(const TacFilter* a, const TacFilter* b, const TacFilter* c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) 
    ConsistencyChecker();
}

void test2(const TacFilter* a, const TacFilter* b, const TacFilter* c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) 
    TransiveChecker();
}

void test3_1(const TacFilter* a, const TacFilter* b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test4(const TacFilter* a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}
