//https://github.com/hluk/CopyQ/commit/4224a97d79a1f745b96d499616b921734814b06d

// Violation of Anti-Symmetry 


bool compare_17(const std::string &lhs, const std::string &rhs) {
    return formatSortPriority(lhs) > formatSortPriority(rhs) || lhs < rhs;
}