#include <bits/stdc++.h>

enum TIFFDataType { TIFF_ANY };
struct TIFFField {
    int field_tag;
    TIFFDataType field_type;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int tagCompare(const void *a, const void *b) {
    const TIFFField *ta = *(const TIFFField **)a;
    const TIFFField *tb = *(const TIFFField **)b;
    
    if (ta->field_tag != tb->field_tag)
        return ta->field_tag - tb->field_tag;
    else
        return (ta->field_type == TIFF_ANY) ? 0 : (tb->field_type - ta->field_type);
}

void test1(const TIFFField *a, const TIFFField *b, const TIFFField *c) {
    NewTest();
    if (!(tagCompare(&a,&b)<0) && !(tagCompare(&b,&c)<0) && (tagCompare(&a,&c)<0))
        ConsistencyChecker();
}

void test2(const TIFFField *a, const TIFFField *b, const TIFFField *c) {
    NewTest();
    if ((tagCompare(&a,&b)<0) && (tagCompare(&b,&c)<0) && (tagCompare(&c,&a)<0))
        TransiveChecker();
}

void test3_1(const TIFFField *a, const TIFFField *b) {
    NewTest();
    if ((tagCompare(&a,&b)>0)&&(tagCompare(&b,&a)>0))
        SymmetryChecker();
}

void test3_2(const TIFFField *a, const TIFFField *b) {
    NewTest();
    if ((tagCompare(&a,&b)<0)&&(tagCompare(&b,&a)<0))
        SymmetryChecker();
}

void test4(const TIFFField *a) {
    NewTest();
    if (tagCompare(&a,&a)<0 || tagCompare(&a,&a)>0)
        ReflexivityChecker();
}