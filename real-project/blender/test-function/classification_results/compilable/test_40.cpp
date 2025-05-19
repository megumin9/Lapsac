#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;

struct KDTreeNode {
    int co[10];
    int d;
};

const uint KD_DIMS = 10;
int kdtree_cmp_bool(bool, bool);

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int kdtree_node_cmp_deduplicate(const void *n0_p, const void *n1_p) {
  const KDTreeNode *n0 = static_cast<const KDTreeNode *>(n0_p);
  const KDTreeNode *n1 = static_cast<const KDTreeNode *>(n1_p);
  for (uint j = 0; j < KD_DIMS; j++) {
    if (n0->co[j] < n1->co[j]) return -1;
    if (n0->co[j] > n1->co[j]) return 1;
  }
  if (n0->d != KD_DIMS && n1->d != KD_DIMS) {
    ((KDTreeNode *)n1)->d = KD_DIMS;
  }
  return kdtree_cmp_bool(n0->d == KD_DIMS, n1->d == KD_DIMS);
}

void test1(const KDTreeNode* a,const KDTreeNode* b,const KDTreeNode* c){
NewTest();
if (!(kdtree_node_cmp_deduplicate(a,b)<0) && !(kdtree_node_cmp_deduplicate(b,c)<0) && (kdtree_node_cmp_deduplicate(a,c)<0))
ConsistencyChecker();
}

void test2(const KDTreeNode* a,const KDTreeNode* b,const KDTreeNode* c){
NewTest();
if ((kdtree_node_cmp_deduplicate(a,b)<0) && (kdtree_node_cmp_deduplicate(b,c)<0) && (kdtree_node_cmp_deduplicate(c,a)<0)) 
TransiveChecker();
}

void test3_2(const KDTreeNode* a,const KDTreeNode* b){
NewTest();
if ((kdtree_node_cmp_deduplicate(a,b)<0)&&(kdtree_node_cmp_deduplicate(b,a)<0))
SymmetryChecker();
}

void test4(const KDTreeNode* a){
NewTest();
if (kdtree_node_cmp_deduplicate(a, a)<0||kdtree_node_cmp_deduplicate(a, a)>0) 
ReflexivityChecker();
}