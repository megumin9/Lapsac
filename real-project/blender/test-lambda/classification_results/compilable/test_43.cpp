#include <string>

struct FieldInput {
    enum Category { A, B, C };
    Category category() const;
    std::string socket_inspection_name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const FieldInput &a, const FieldInput &b) {
  const int index_a = int(a.category());
  const int index_b = int(b.category());
  if (index_a == index_b) {
    return a.socket_inspection_name().size() < b.socket_inspection_name().size();
  }
  return index_a < index_b;
}

void test1(const FieldInput &a, const FieldInput &b, const FieldInput &c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
ConsistencyChecker();
}

void test2(const FieldInput &a, const FieldInput &b, const FieldInput &c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
TransiveChecker();
}

void test3_1(const FieldInput &a, const FieldInput &b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test3_2(const FieldInput &a, const FieldInput &b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(const FieldInput &a){
NewTest();
if (lambda0(a, a)) 
ReflexivityChecker();
}