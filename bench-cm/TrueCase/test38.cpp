// https://github.com/xwiki/xwiki-platform/commit/f01376a1fccf621ae63344d1ad998a2bb83b63b3

int compare_38(Object &a, Object &b) {
  return a.getPriority() - b.getPriority();
}