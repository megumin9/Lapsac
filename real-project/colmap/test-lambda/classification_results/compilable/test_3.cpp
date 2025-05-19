#include <bits/stdc++.h>
struct TrackElement {};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<TrackElement, std::string>& track_el1,
             const std::pair<TrackElement, std::string>& track_el2) {
  return track_el1.second < track_el2.second;
}

void test1(const std::pair<TrackElement, std::string>& a, const std::pair<TrackElement, std::string>& b, const std::pair<TrackElement, std::string>& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
  ConsistencyChecker();
}

void test2(const std::pair<TrackElement, std::string>& a, const std::pair<TrackElement, std::string>& b, const std::pair<TrackElement, std::string>& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
  TransiveChecker();
}

void test3_1(const std::pair<TrackElement, std::string>& a, const std::pair<TrackElement, std::string>& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
  SymmetryChecker();
}

void test3_2(const std::pair<TrackElement, std::string>& a, const std::pair<TrackElement, std::string>& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
  SymmetryChecker();
}

void test4(const std::pair<TrackElement, std::string>& a) {
  NewTest();
  if (lambda0(a, a))
  ReflexivityChecker();
}