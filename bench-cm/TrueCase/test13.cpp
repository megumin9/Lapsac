//https://github.com/ceph/ceph/commit/830e72ab9d66c8f5703ea27da5249b02dd16ccd0

bool compare_13(const GroupSnapshotNamespace& a, const GroupSnapshotNamespace& b){
  if (a.group_pool != b.group_pool) {
    return a.group_pool < b.group_pool;
  }
  if (a.group_id != b.group_id) {
    return a.group_id < b.group_id;
  }
  return a.group_snapshot_id < b.group_snapshot_id;
}