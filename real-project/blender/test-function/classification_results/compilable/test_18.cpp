#include <bits/stdc++.h>

struct tPaletteColorHSV {
    int rgb[3];
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int palettecolor_compare_luminance(const void *a1, const void *a2) {
  const tPaletteColorHSV *ps1 = static_cast<const tPaletteColorHSV *>(a1);
  const tPaletteColorHSV *ps2 = static_cast<const tPaletteColorHSV *>(a2);

  float lumi1 = (ps1->rgb[0] + ps1->rgb[1] + ps1->rgb[2]) / 3.0f;
  float lumi2 = (ps2->rgb[0] + ps2->rgb[1] + ps2->rgb[2]) / 3.0f;

  if (lumi1 > lumi2) {
    return -1;
  }
  if (lumi1 < lumi2) {
    return 1;
  }

  return 0;
}

void test1(const tPaletteColorHSV* a, const tPaletteColorHSV* b, const tPaletteColorHSV* c) {
NewTest();
if (!(palettecolor_compare_luminance(a,b)<0) && !(palettecolor_compare_luminance(b,c)<0) && (palettecolor_compare_luminance(a,c)<0))
ConsistencyChecker();
}

void test2(const tPaletteColorHSV* a, const tPaletteColorHSV* b, const tPaletteColorHSV* c) {
NewTest();
if ((palettecolor_compare_luminance(a,b)<0) && (palettecolor_compare_luminance(b,c)<0) && (palettecolor_compare_luminance(c,a)<0)) 
TransiveChecker();
}

void test3_1(const tPaletteColorHSV* a, const tPaletteColorHSV* b) {
NewTest();
if ((palettecolor_compare_luminance(a,b)>0)&&(palettecolor_compare_luminance(b,a)>0))
SymmetryChecker();
}

void test3_2(const tPaletteColorHSV* a, const tPaletteColorHSV* b) {
NewTest();
if ((palettecolor_compare_luminance(a,b)<0)&&(palettecolor_compare_luminance(b,a)<0))
SymmetryChecker();
}

void test4(const tPaletteColorHSV* a) {
NewTest();
if (palettecolor_compare_luminance(a, a)<0||palettecolor_compare_luminance(a, a)>0) 
ReflexivityChecker();
}