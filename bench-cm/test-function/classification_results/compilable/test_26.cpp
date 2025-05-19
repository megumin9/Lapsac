#include <bits/stdc++.h>
#include <memory>
#include <string>

class ResolvedJavaMethod;
class LineNumberTable;

struct HostedMethod {
    struct Wrapped {
        void* wrapped;
    };
    Wrapped wrapped;
};

class CEntryPointCallStubSupport {
public:
    static CEntryPointCallStubSupport& singleton();
    std::shared_ptr<ResolvedJavaMethod> getMethodForStub(void* stub);
};

class ResolvedJavaMethod {
public:
    class JavaClass {
    public:
        std::string getSourceFileName() const;
    };
    JavaClass* getDeclaringClass() const;
    LineNumberTable* getLineNumberTable() const;
};

class LineNumberTable {
public:
    int getLineNumber(int) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_30(HostedMethod* stub1, HostedMethod* stub2) {
    std::shared_ptr<ResolvedJavaMethod> rm1 = CEntryPointCallStubSupport::singleton().getMethodForStub(stub1->wrapped.wrapped);
    std::shared_ptr<ResolvedJavaMethod> rm2 = CEntryPointCallStubSupport::singleton().getMethodForStub(stub2->wrapped.wrapped);

    int fileComparison = rm1->getDeclaringClass()->getSourceFileName().compare(rm2->getDeclaringClass()->getSourceFileName());
    if (fileComparison != 0) {
        return fileComparison;
    } else if (rm1->getLineNumberTable() && rm2->getLineNumberTable()) {
        return rm1->getLineNumberTable()->getLineNumber(0) - rm2->getLineNumberTable()->getLineNumber(0);
    }
    return 0;
}

void test1(HostedMethod* a, HostedMethod* b, HostedMethod* c) {
    NewTest();
    if (!(compare_30(a,b)<0) && !(compare_30(b,c)<0) && (compare_30(a,c)<0))
        ConsistencyChecker();
}

void test2(HostedMethod* a, HostedMethod* b, HostedMethod* c) {
    NewTest();
    if ((compare_30(a,b)<0) && (compare_30(b,c)<0) && (compare_30(c,a)<0))
        TransiveChecker();
}

void test3_1(HostedMethod* a, HostedMethod* b) {
    NewTest();
    if ((compare_30(a,b)>0) && (compare_30(b,a)>0))
        SymmetryChecker();
}

void test3_2(HostedMethod* a, HostedMethod* b) {
    NewTest();
    if ((compare_30(a,b)<0) && (compare_30(b,a)<0))
        SymmetryChecker();
}

void test4(HostedMethod* a) {
    NewTest();
    if (compare_30(a,a)<0 || compare_30(a,a)>0)
        ReflexivityChecker();
}