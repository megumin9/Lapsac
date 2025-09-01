// https://github.com/DeNA/DeClang/commit/976f8605e29c1fc5b16ec0bd6c2cb117a8e73d7d


bool compare_36(OutputSectionBase *A, OutputSectionBase *B) {
 
  if ((A->getType() == SHT_NOBITS || B->getType() == SHT_NOBITS) && A->getType() != B->getType())
    return A->getType() != SHT_NOBITS && B->getType() == SHT_NOBITS;

  return getPPC64SectionRank(A->getName()) < getPPC64SectionRank(B->getName());
}