#include <bits/stdc++.h>

struct NodeDef {
    std::string op() const;
    std::string name() const;
    int input_size() const;
    const std::string& input(int) const;
};

struct GraphDef {
    int node_size() const;
    const NodeDef& node(int) const;
};

std::vector<int> CreateNameIndex(const GraphDef&);
std::vector<int> CreateInputIndex(const NodeDef&);
bool IsSameInput(const std::string&, const std::string&);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool Compare(const GraphDef& g1, const GraphDef& g2) {
  if (g1.node_size() != g2.node_size()) {
    return false;
  }
  std::vector<int> name_index1 = CreateNameIndex(g1);
  std::vector<int> name_index2 = CreateNameIndex(g2);
  for (int i = 0; i < g1.node_size(); ++i) {
    int idx1 = name_index1[i];
    int idx2 = name_index2[i];
    if (g1.node(idx1).op() != g2.node(idx2).op()) {
      return false;
    }
    if (g1.node(idx1).name() != g2.node(idx2).name()) {
      return false;
    }
    if (g1.node(idx1).input_size() != g2.node(idx2).input_size()) {
      return false;
    }
    std::vector<int> input_index1 = CreateInputIndex(g1.node(idx1));
    std::vector<int> input_index2 = CreateInputIndex(g2.node(idx2));
    for (int j = 0; j < g1.node(idx1).input_size(); ++j) {
      if (!IsSameInput(g1.node(idx1).input(input_index1[j]),
                       g2.node(idx2).input(input_index2[j]))) {
        return false;
      }
    }
  }
  return true;
}

void test1(GraphDef a, GraphDef b, GraphDef c){
  NewTest();
  if (!Compare(a,b) && !Compare(b,c) && Compare(a,c))
    ConsistencyChecker();
}

void test2(GraphDef a, GraphDef b, GraphDef c){
  NewTest();
  if (Compare(a,b) && Compare(b,c) && Compare(c,a))
    TransiveChecker();
}

void test3_1(GraphDef a, GraphDef b){
  NewTest();
  if (Compare(a,b) && Compare(b,a))
    SymmetryChecker();
}

void test4(GraphDef a){
  NewTest();
  if (Compare(a, a))
    ReflexivityChecker();
}