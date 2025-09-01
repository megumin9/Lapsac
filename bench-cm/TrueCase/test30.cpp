// https://github.com/oracle/graal/commit/4a3b9a4d385b4b8f84a1f034f5bb7689094b2561


int compare_30(HostedMethod* stub1, HostedMethod* stub2) {
    std::shared_ptr<ResolvedJavaMethod> rm1 = CEntryPointCallStubSupport::singleton().getMethodForStub(stub1->wrapped.wrapped);
    std::shared_ptr<ResolvedJavaMethod> rm2 = CEntryPointCallStubSupport::singleton().getMethodForStub(stub2->wrapped.wrapped);

    int fileComparison = rm1->getDeclaringClass()->getSourceFileName().compare(rm2->getDeclaringClass()->getSourceFileName());
    if (fileComparison != 0) {
        return fileComparison;
    }

    int rm1Line = rm1->getLineNumberTable() != nullptr ? rm1->getLineNumberTable()->getLineNumber(0) : -1;
    int rm2Line = rm2->getLineNumberTable() != nullptr ? rm2->getLineNumberTable()->getLineNumber(0) : -1;
    return rm1Line - rm2Line;
}
