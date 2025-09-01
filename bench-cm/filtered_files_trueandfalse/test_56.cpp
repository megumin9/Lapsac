#include <bits/stdc++.h>
#include <strings.h>

class FileObject {
public:
    bool isDir() const;
    const char* GetPath() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_39(const FileObject * fo1, const FileObject * fo2) {
    int res = 0;
    if (fo1->isDir() != fo2->isDir()) {
        res = fo1->isDir()?-1:1;
    } else {
        res = strcasecmp(fo1->GetPath(), fo2->GetPath());
    }
    return (res < 0);
}

void test1(const FileObject* a,const FileObject* b,const FileObject* c){
    NewTest();
    if (!compare_39(a,b) &&!compare_39(b,c) && compare_39(a,c))
    ConsistencyChecker();
}

void test2(const FileObject* a,const FileObject* b,const FileObject* c){
    NewTest();
    if (compare_39(a,b) && compare_39(b,c) && compare_39(c,a))
    TransiveChecker();
}

void test3_1(const FileObject* a,const FileObject* b){
    NewTest();
    if (compare_39(a,b) && compare_39(b,a))
    SymmetryChecker();
}

void test3_2(const FileObject* a,const FileObject* b){
    NewTest();
    if (compare_39(a,b) && compare_39(b,a))
    SymmetryChecker();
}

void test4(const FileObject* a){
    NewTest();
    if (compare_39(a, a))
    ReflexivityChecker();
}