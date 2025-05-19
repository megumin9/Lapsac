#include <bits/stdc++.h>

struct UsageRecord {
    size_t tensor_size;
};

template<typename T>
struct TensorUsageWithIndex {
    UsageRecord* usage_record;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool CompareBySize(const TensorUsageWithIndex<size_t>& first,
                   const TensorUsageWithIndex<size_t>& second) {
  return first.usage_record->tensor_size > second.usage_record->tensor_size;
}

void test1(TensorUsageWithIndex<size_t> a, TensorUsageWithIndex<size_t> b, TensorUsageWithIndex<size_t> c){
NewTest();
if (!CompareBySize(a,b) && !CompareBySize(b,c) && CompareBySize(a,c))
ConsistencyChecker();
}

void test2(TensorUsageWithIndex<size_t> a, TensorUsageWithIndex<size_t> b, TensorUsageWithIndex<size_t> c){
NewTest();
if (CompareBySize(a,b) && CompareBySize(b,c) && CompareBySize(c,a))
TransiveChecker();
}

void test3_1(TensorUsageWithIndex<size_t> a, TensorUsageWithIndex<size_t> b){
NewTest();
if (CompareBySize(a,b) && CompareBySize(b,a))
SymmetryChecker();
}

void test3_2(TensorUsageWithIndex<size_t> a, TensorUsageWithIndex<size_t> b){
NewTest();
if (CompareBySize(a,b) && CompareBySize(b,a))
SymmetryChecker();
}

void test4(TensorUsageWithIndex<size_t> a){
NewTest();
if (CompareBySize(a, a))
ReflexivityChecker();
}