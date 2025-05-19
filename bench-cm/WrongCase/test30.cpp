// https://github.com/oracle/graal/commit/4a3b9a4d385b4b8f84a1f034f5bb7689094b2561

// Violation of Consistency

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
