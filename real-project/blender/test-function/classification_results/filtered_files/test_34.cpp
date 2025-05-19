#include <bits/stdc++.h>
using namespace std;

struct Panel {
    int sortorder;
};

struct PanelSort {
    Panel* panel;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_panel(const void *a, const void *b) {
  const Panel *panel_a = ((PanelSort *)a)->panel;
  const Panel *panel_b = ((PanelSort *)b)->panel;

  if (panel_a->sortorder > panel_b->sortorder) {
    return 1;
  }
  if (panel_a->sortorder < panel_b->sortorder) {
    return -1;
  }

  return 0;
}

void test1(void *a, void *b, void *c){
NewTest();
if (!(compare_panel(a,b)<0) && !(compare_panel(b,c)<0) && (compare_panel(a,c)<0))
ConsistencyChecker();
}

void test2(void *a, void *b, void *c){
NewTest();
if ((compare_panel(a,b)<0) && (compare_panel(b,c)<0) && (compare_panel(c,a)<0))
TransiveChecker();
}

void test3_1(void *a, void *b){
NewTest();
if ((compare_panel(a,b)>0)&&(compare_panel(b,a)>0))
SymmetryChecker();
}

void test3_2(void *a, void *b){
NewTest();
if ((compare_panel(a,b)<0)&&(compare_panel(b,a)<0))
SymmetryChecker();
}

void test4(void *a){
NewTest();
if (compare_panel(a, a)<0||compare_panel(a, a)>0) 
ReflexivityChecker();
}