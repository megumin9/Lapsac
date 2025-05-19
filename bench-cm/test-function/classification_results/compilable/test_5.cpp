#include <bits/stdc++.h>

struct CM_HIT {
    int evalue;
    int score;
    int seq_idx;
    int start;
    int pass_idx;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_8(const void *vh1, const void *vh2) {
  CM_HIT *h1 = *((CM_HIT **) vh1);  
  CM_HIT *h2 = *((CM_HIT **) vh2);
 
  if      (h1->evalue > h2->evalue) return  1; 
  else if (h1->evalue < h2->evalue) return -1;
  else { 
    if      (h1->score < h2->score) return  1; 
    else if (h1->score > h2->score) return -1;
    else {
      if      (h1->seq_idx > h2->seq_idx) return  1; 
      else if (h1->seq_idx < h2->seq_idx) return -1;
      else {
 	      if      (h1->start > h2->start) return  1; 
 	      else if (h1->start < h2->start) return -1;
 	      else                            return  (h1->pass_idx < h2->pass_idx ? 1 : -1 ); 
      }
    }
  }
}

void test1(CM_HIT* a, CM_HIT* b, CM_HIT* c){
NewTest();
if (!(compare_8(&a,&b)<0) && !(compare_8(&b,&c)<0) && (compare_8(&a,&c)<0))
ConsistencyChecker();
}

void test2(CM_HIT* a, CM_HIT* b, CM_HIT* c){
NewTest();
if ((compare_8(&a,&b)<0) && (compare_8(&b,&c)<0) && (compare_8(&c,&a)<0)) 
TransiveChecker();
}

void test3_1(CM_HIT* a, CM_HIT* b){
NewTest();
if ((compare_8(&a,&b)>0)&&(compare_8(&b,&a)>0))
SymmetryChecker();
}

void test3_2(CM_HIT* a, CM_HIT* b){
NewTest();
if ((compare_8(&a,&b)<0)&&(compare_8(&b,&a)<0))
SymmetryChecker();
}

void test4(CM_HIT* a){
NewTest();
if (compare_8(&a, &a)<0||compare_8(&a, &a)>0) 
ReflexivityChecker();
}