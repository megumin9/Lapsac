// https://github.com/v8/v8/commit/5ff7901e24c2c6029114567de5a08ed0f1494c81

// Violation of Anti-Symmetry 

bool compare_9(const Candidate& left, const Candidate& right) {
  return left.node != right.node && left.calls >= right.calls;
}