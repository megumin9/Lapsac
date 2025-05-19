
#include <bits/stdc++.h>

struct TIFFEntryOffsetAndLength {
    int offset;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int cmpTIFFEntryOffsetAndLength(const void *a, const void *b) {
    const TIFFEntryOffsetAndLength *ta = static_cast<const TIFFEntryOffsetAndLength*>(a);
    const TIFFEntryOffsetAndLength *tb = static_cast<const TIFFEntryOffsetAndLength*>(b);
    
    if (ta->offset > tb->offset)
        return 1;
    else if (ta->offset < tb->offset)
        return -1;
    else
        return 0;
}

void test1(const TIFFEntryOffsetAndLength* a, const TIFFEntryOffsetAndLength* b, const TIFFEntryOffsetAndLength* c) {
    NewTest();
    if (!(cmpTIFFEntryOffsetAndLength(a,b)<0) && !(cmpTIFFEntryOffsetAndLength(b,c)<0) && (cmpTIFFEntryOffsetAndLength(a,c)<0))
        ConsistencyChecker();
}

void test2(const TIFFEntryOffsetAndLength* a, const TIFFEntryOffsetAndLength* b, const TIFFEntryOffsetAndLength* c) {
    NewTest();
    if ((cmpTIFFEntryOffsetAndLength(a,b)<0) && (cmpTIFFEntryOffsetAndLength(b,c)<0) && (cmpTIFFEntryOffsetAndLength(c,a)<0))
        TransiveChecker();
}

void test3_1(const TIFFEntryOffsetAndLength* a, const TIFFEntryOffsetAndLength* b) {
    NewTest();
    if ((cmpTIFFEntryOffsetAndLength(a,b)>0)&&(cmpTIFFEntryOffsetAndLength(b,a)>0))
        SymmetryChecker();
}

void test3_2(const TIFFEntryOffsetAndLength* a, const TIFFEntryOffsetAndLength* b) {
    NewTest();
    if ((cmpTIFFEntryOffsetAndLength(a,b)<0)&&(cmpTIFFEntryOffsetAndLength(b,a)<0))
        SymmetryChecker();
}

void test4(const TIFFEntryOffsetAndLength* a) {
    NewTest();
    if (cmpTIFFEntryOffsetAndLength(a, a)<0 || cmpTIFFEntryOffsetAndLength(a, a)>0) 
        ReflexivityChecker();
}
