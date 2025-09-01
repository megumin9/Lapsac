// https://github.com/google/swiftshader/commit/126d9d604e2714f7d25a3a683f9a687727f5dfb8



bool compare_26(const ComputeProgramKey &a, const ComputeProgramKey &b) 
{
  if (a.shader < b.shader) return true;
  if (a.shader > b.shader) return false;
  if (a.layout < b.layout) return true;
  return false;
}