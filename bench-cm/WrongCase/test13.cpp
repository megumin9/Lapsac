//https://github.com/ceph/ceph/commit/830e72ab9d66c8f5703ea27da5249b02dd16ccd0

//Violation of Anti-Symmetry 

bool compare_13(const GroupSnapshotNamespace& a, const GroupSnapshotNamespace& b){
  if (a.group_pool < b.group_pool) {
    return true;
  } else if (a.group_id < b.group_id) {
    return true;
  } else {
    return (a.group_snapshot_id < b.group_snapshot_id);
  }
  return false;
}