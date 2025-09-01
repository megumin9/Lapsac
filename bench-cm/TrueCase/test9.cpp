// https://github.com/v8/v8/commit/5ff7901e24c2c6029114567de5a08ed0f1494c81

bool compare_9(const Candidate& left, const Candidate& right) {
  if (left.calls != right.calls) {
    return left.calls > right.calls;
  }
  return left.node < right.node;
}
