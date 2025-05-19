// https://github.com/xwiki/xwiki-platform/commit/f01376a1fccf621ae63344d1ad998a2bb83b63b3

// Violation of Transitivity

int compare_38(Object &a, Object &b) {
  if (a.hasPriority() && b.hasPriority()) {
    return a.getPriority() - b.getPriority();
  }
  return   a.getClassName().compare((b.getClassName()));
}
