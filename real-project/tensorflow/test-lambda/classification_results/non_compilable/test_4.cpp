#include <bits/stdc++.h>
#include <utility>
#include <string>
#include "tensorflow/core/protobuf/meta_graph.h"

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<std::string, ::tensorflow::SignatureDef>& a,
             const std::pair<std::string, ::tensorflow::SignatureDef>& b) {
  return a.first < b.first;
}

void test1(const std::pair<std::string, ::tensorflow::SignatureDef>& a,
           const std::pair<std::string, ::tensorflow::SignatureDef>& b,
           const std::pair<std::string, ::tensorflow::SignatureDef>& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
  ConsistencyChecker();
}

void test2(const std::pair<std::string, ::tensorflow::SignatureDef>& a,
           const std::pair<std::string, ::tensorflow::SignatureDef>& b,
           const std::pair<std::string, ::tensorflow::SignatureDef>& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
  TransiveChecker();
}

void test3_1(const std::pair<std::string, ::tensorflow::SignatureDef>& a,
             const std::pair<std::string, ::tensorflow::SignatureDef>& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
  SymmetryChecker();
}

void test3_2(const std::pair<std::string, ::tensorflow::SignatureDef>& a,
             const std::pair<std::string, ::tensorflow::SignatureDef>& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
  SymmetryChecker();
}

void test4(const std::pair<std::string, ::tensorflow::SignatureDef>& a) {
  NewTest();
  if (lambda0(a, a))
  ReflexivityChecker();
}