// https://github.com/DeNA/DeClang/commit/976f8605e29c1fc5b16ec0bd6c2cb117a8e73d7d


bool compare_35(EdgeWeight X, EdgeWeight Y) {
  if (X.second > Y.second) return true;
  if (X.second < Y.second) return false;

  const BasicBlock *BBX_1 = dynamic_cast<const BasicBlock*>(X.first.first);
  const BasicBlock *BBY_1 = dynamic_cast<const BasicBlock*>(Y.first.first);
  if (BBX_1->getsize() > BBY_1->getsize()) return true;
  if (BBX_1->getsize() < BBY_1->getsize()) return false;

  const BasicBlock *BBX_2 = dynamic_cast<const BasicBlock*>(X.first.second);
  const BasicBlock *BBY_2 = dynamic_cast<const BasicBlock*>(Y.first.second);
  if (BBX_2->getsize() > BBY_2->getsize()) return true;
  if (BBX_2->getsize() < BBY_2->getsize()) return false;

  return false;
}
