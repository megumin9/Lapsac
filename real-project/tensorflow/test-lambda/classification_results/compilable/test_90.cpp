#include <string>

class CoordinatedTask {
public:
    std::string job_name() const;
    int task_id() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const CoordinatedTask& task1, const CoordinatedTask& task2) {
  if (task1.job_name() != task2.job_name()) {
    return task1.job_name() < task2.job_name();
  }
  return task1.task_id() < task2.task_id();
}

void test1(CoordinatedTask a, CoordinatedTask b, CoordinatedTask c) {
  NewTest();
  if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c))
    ConsistencyChecker();
}

void test2(CoordinatedTask a, CoordinatedTask b, CoordinatedTask c) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a))
    TransiveChecker();
}

void test3_1(CoordinatedTask a, CoordinatedTask b) {
  NewTest();
  if (lambda0(a, b) && lambda0(b, a))
    SymmetryChecker();
}

void test4(CoordinatedTask a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}