#include <bits/stdc++.h>
using namespace std;

struct tPaletteColorHSV {
    float h;
    float s;
    float v;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int palettecolor_compare_vhs(const void *a1, const void *a2) {
  const tPaletteColorHSV *ps1 = static_cast<const tPaletteColorHSV *>(a1);
  const tPaletteColorHSV *ps2 = static_cast<const tPaletteColorHSV *>(a2);

  if (1.0f - ps1->v > 1.0f - ps2->v) return 1;
  if (1.0f - ps1->v < 1.0f - ps2->v) return -1;
  
  if (ps1->h > ps2->h) return 1;
  if (ps1->h < ps2->h) return -1;
  
  if (ps1->s > ps2->s) return 1;
  if (ps1->s < ps2->s) return -1;
  
  return 0;
}

void test1(const void* a, const void* b, const void* c){
NewTest();
if (!(palettecolor_compare_vhs(a,b)<0) && !(palettecolor_compare_vhs(b,c)<0) && (palettecolor_compare_vhs(a,c)<0)) 
ConsistencyChecker();
}

void test2(const void* a, const void* b, const void* c){
NewTest();
if ((palettecolor_compare_vhs(a,b)<0) && (palettecolor_compare_vhs(b,c)<0) && (palettecolor_compare_vhs(c,a)<0)) 
TransiveChecker();
}

void test3_1(const void* a, const void* b){
NewTest();
if ((palettecolor_compare_vhs(a,b)>0)&&(palettecolor_compare_vhs(b,a)>0))
SymmetryChecker();
}

void test3_2(const void* a, const void* b){
NewTest();
if ((palettecolor_compare_vhs(a,b)<0)&&(palettecolor_compare_vhs(b,a)<0))
SymmetryChecker();
}

void test4(const void* a){
NewTest();
if (palettecolor_compare_vhs(a, a)<0||palettecolor_compare_vhs(a, a)>0) 
ReflexivityChecker();
}