#include <bits/stdc++.h>

struct infer_result {
    int probability;
    int class_id;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare(const void* a, const void* b) {
    const struct infer_result* sa = (const struct infer_result*)a;
    const struct infer_result* sb = (const struct infer_result*)b;
    if (sa->probability < sb->probability) {
        return 1;
    } else if ((sa->probability == sb->probability) && (sa->class_id > sb->class_id)) {
        return 1;
    } else if (sa->probability > sb->probability) {
        return -1;
    }
    return 0;
}

void test1(struct infer_result* a, struct infer_result* b, struct infer_result* c){
    NewTest();
    if (!(compare(a,b)<0) && !(compare(b,c)<0) && (compare(a,c)<0))
        ConsistencyChecker();
}

void test2(struct infer_result* a, struct infer_result* b, struct infer_result* c){
    NewTest();
    if ((compare(a,b)<0) && (compare(b,c)<0) && (compare(c,a)<0))
        TransiveChecker();
}

void test3_1(struct infer_result* a, struct infer_result* b){
    NewTest();
    if ((compare(a,b)>0)&&(compare(b,a)>0))
        SymmetryChecker();
}

void test3_2(struct infer_result* a, struct infer_result* b){
    NewTest();
    if ((compare(a,b)<0)&&(compare(b,a)<0))
        SymmetryChecker();
}

void test4(struct infer_result* a){
    NewTest();
    if (compare(a,a)<0||compare(a,a)>0) 
        ReflexivityChecker();
}