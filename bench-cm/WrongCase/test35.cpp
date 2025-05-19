// https://github.com/DeNA/DeClang/commit/976f8605e29c1fc5b16ec0bd6c2cb117a8e73d7d

// Violation of Transitivity
bool compare_35(EdgeWeight X, EdgeWeight Y){
  if (X.second > Y.second) return true;
  if (X.second < Y.second) return false;

  if (const BasicBlock *BBX = dynamic_cast<const BasicBlock*>(X.first.first)) {
  if (const BasicBlock *BBY = dynamic_cast<const BasicBlock*>(Y.first.first)) {
      if (BBX->getsize() > BBY->getsize()) return true;
      if (BBX->getsize() < BBY->getsize()) return false;
    }
  }

  if (const BasicBlock *BBX = dynamic_cast<const BasicBlock*>(X.first.second)) {
  if (const BasicBlock *BBY = dynamic_cast<const BasicBlock*>(Y.first.second)) {
      if (BBX->getsize() > BBY->getsize()) return true;
      if (BBX->getsize() < BBY->getsize()) return false;
    }
  }

  return false;
}
