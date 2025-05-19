// https://github.com/ydb-platform/ydb/commit/a5e59f3f127307668fe6f01b4920537bc31f0718

// Violation of Anti-Reflexivity

bool compare_22(const TPartitionInfo& a, const TPartitionInfo& b) { 
    return !b.ToBound || (a.ToBound && *a.ToBound < *b.ToBound); 
}