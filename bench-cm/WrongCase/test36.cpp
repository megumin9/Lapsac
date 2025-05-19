// https://github.com/DeNA/DeClang/commit/0d7e83bbc49373504cc634d9208422102c15d575

// Violation of Consistency


bool compare_36(OutputSectionBase *A, OutputSectionBase *B) {
 
  if (A->getType() != B->getType())
    return A->getType() != SHT_NOBITS && B->getType() == SHT_NOBITS;

  return getPPC64SectionRank(A->getName()) < getPPC64SectionRank(B->getName());
}