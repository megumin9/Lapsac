#include <bits/stdc++.h>
using namespace std;

struct CommandHandler {
    int id;
};
using CommandHandlerPtr = shared_ptr<CommandHandler>;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const CommandHandlerPtr &a, const CommandHandlerPtr &b) {
  return a->id < b->id;
}

void test1(const CommandHandlerPtr &a, const CommandHandlerPtr &b, const CommandHandlerPtr &c) {
  NewTest();
  if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const CommandHandlerPtr &a, const CommandHandlerPtr &b, const CommandHandlerPtr &c) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const CommandHandlerPtr &a, const CommandHandlerPtr &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const CommandHandlerPtr &a, const CommandHandlerPtr &b) {
  NewTest();
  if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const CommandHandlerPtr &a) {
  NewTest();
  if (lambda0(a, a))
    ReflexivityChecker();
}