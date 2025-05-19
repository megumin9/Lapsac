// https://github.com/Floorp-Projects/Floorp/commit/dc24cba10cec181cf04f68d3c28fa6abdf11102e

// Violation of Consistency

bool compare_18(const std::unique_ptr<Network>& a,
                     const std::unique_ptr<Network>& b) {
  if (a->prefix_length() == b->prefix_length()) {
    if (a->name() == b->name()) {
      return a->prefix() < b->prefix();
    }
  }
  return a->name() < b->name();
}