
#include <bits/stdc++.h>

struct album {
    const char *name;
    int date;
    int is_compilation;
    const char *collkey_name;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_27(const struct album *a, const struct album *b) {
    int cmp = (*a->name != '<') - (*b->name != '<');

    if (cmp)
        return cmp;

    if (a->date != b->date && !a->is_compilation && !b->is_compilation)
        return a->date - b->date;

    return strcmp(a->collkey_name, b->collkey_name);
}

void test1(const struct album *a, const struct album *b, const struct album *c){
    NewTest();
    if (!(compare_27(a,b)<0) && !(compare_27(b,c)<0) && (compare_27(a,c)<0))
        ConsistencyChecker();
}

void test2(const struct album *a, const struct album *b, const struct album *c){
    NewTest();
    if ((compare_27(a,b)<0) && (compare_27(b,c)<0) && (compare_27(c,a)<0))
        TransiveChecker();
}

void test3_1(const struct album *a, const struct album *b){
    NewTest();
    if ((compare_27(a,b)>0)&&(compare_27(b,a)>0))
        SymmetryChecker();
}

void test3_2(const struct album *a, const struct album *b){
    NewTest();
    if ((compare_27(a,b)<0)&&(compare_27(b,a)<0))
        SymmetryChecker();
}

void test4(const struct album *a){
    NewTest();
    if (compare_27(a, a)<0||compare_27(a, a)>0) 
        ReflexivityChecker();
}
