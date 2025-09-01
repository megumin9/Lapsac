// https://github.com/tenzir/tenzir/commit/0a70e6fb21fc7d0fdf5abac995a0f47529d34d68


bool compare_33(const container_view_handle<Pointer>& x, const container_view_handle<Pointer>& y) {
    if (!x)
        return static_cast<bool>(y); 
    if (!y)
        return false; 
    return *x < *y;  
}