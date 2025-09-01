//https://github.com/hluk/CopyQ/commit/4224a97d79a1f745b96d499616b921734814b06d


bool compare_17(const std::string &lhs, const std::string &rhs) {
  const int lhsPriority = formatSortPriority(lhs);
  const int rhsPriority = formatSortPriority(rhs);
  return lhsPriority == rhsPriority ? lhs < rhs : lhsPriority > rhsPriority;
}