// https://github.com/google/swiftshader/commit/126d9d604e2714f7d25a3a683f9a687727f5dfb8

// Violation of Anti-Symmetry 

bool compare_26(const ComputeProgramKey &a, const ComputeProgramKey &b) 
{
    return (a.shader < b.shader) || (a.layout < b.layout);
}