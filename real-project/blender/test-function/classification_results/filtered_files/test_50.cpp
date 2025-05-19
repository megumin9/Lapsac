#include <bits/stdc++.h>
using namespace std;

struct Cell {
    int block_id;
    int position;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool CellLessThan(const Cell& lhs, const Cell& rhs) {
  if (lhs.block_id == rhs.block_id) {
    return (lhs.position < rhs.position);
  }
  return (lhs.block_id < rhs.block_id);
}

void test1(Cell a, Cell b, Cell c){
  NewTest();
  if (!CellLessThan(a,b) && !CellLessThan(b,c) && CellLessThan(a,c))
    ConsistencyChecker();
}

void test2(Cell a, Cell b, Cell c){
  NewTest();
  if (CellLessThan(a,b) && CellLessThan(b,c) && CellLessThan(c,a))
    TransiveChecker();
}

void test3_1(Cell a, Cell b){
  NewTest();
  if (CellLessThan(a,b) && CellLessThan(b,a))
    SymmetryChecker();
}

void test4(Cell a){
  NewTest();
  if (CellLessThan(a, a))
    ReflexivityChecker();
}