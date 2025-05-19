
#include <bits/stdc++.h>

struct Participant {
    int gpu_device_id;
    std::string executor;
    int global_rank;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::unique_ptr<Participant>& a, const std::unique_ptr<Participant>& b) {
  if (a->gpu_device_id != b->gpu_device_id) {
    return a->gpu_device_id < b->gpu_device_id;
  }
  if (a->executor != b->executor) {
    return a->executor < b->executor;
  }
  return a->global_rank < b->global_rank;
}

void test1(const std::unique_ptr<Participant>& a, 
          const std::unique_ptr<Participant>& b,
          const std::unique_ptr<Participant>& c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
    ConsistencyChecker();
}

void test2(const std::unique_ptr<Participant>& a,
          const std::unique_ptr<Participant>& b,
          const std::unique_ptr<Participant>& c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const std::unique_ptr<Participant>& a,
            const std::unique_ptr<Participant>& b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const std::unique_ptr<Participant>& a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}
