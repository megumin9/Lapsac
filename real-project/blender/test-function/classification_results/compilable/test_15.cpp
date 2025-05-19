#include <bits/stdc++.h>

struct tPaletteColorHSV {
    int h;
    int s;
    int v;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int palettecolor_compare_hsv(const void *a1, const void *a2) {
  const tPaletteColorHSV *ps1 = static_cast<const tPaletteColorHSV *>(a1);
  const tPaletteColorHSV *ps2 = static_cast<const tPaletteColorHSV *>(a2);

  if (ps1->h > ps2->h) {
    return 1;
  }
  if (ps1->h < ps2->h) {
    return -1;
  }

  if (ps1->s > ps2->s) {
    return 1;
  }
  if (ps1->s < ps2->s) {
    return -1;
  }

  if (ps1->v < ps2->v) {
    return 1;
  }
  if (ps1->v > ps2->v) {
    return -1;
  }

  return 0;
}

void test1(void* a, void* b, void* c){
NewTest();
if (!(palettecolor_compare_hsv(a,b)<0) && !(palettecolor_compare_hsv(b,c)<0) && (palettecolor_compare_hsv(a,c)<0)) 
ConsistencyChecker();
}

void test2(void* a, void* b, void* c){
NewTest();
if ((palettecolor_compare_hsv(a,b)<0) && (palettecolor_compare_hsv(b,c)<0) && (palettecolor_compare_hsv(c,a)<0)) 
TransiveChecker();
}

void test3_1(void* a, void* b){
NewTest();
if ((palettecolor_compare_hsv(a,b)>0)&&(palettecolor_compare_hsv(b,a)>0))
SymmetryChecker();
}

void test3_2(void* a, void* b){
NewTest();
if ((palettecolor_compare_hsv(a,b)<0)&&(palettecolor_compare_hsv(b,a)<0))
SymmetryChecker();
}

void test4(void* a){
NewTest();
if (palettecolor_compare_hsv(a, a)<0||palettecolor_compare_hsv(a, a)>0) 
ReflexivityChecker();
}