// https://github.com/blender/blender/commit/50f2857b1a844b3173c4ea6ad3b294c51c6781b6

// Violation of Anti-Reflexivity


bool compare_5(ID* a, ID* b) {
    int* order_a = id_order_get(a);
    int* order_b = id_order_get(b);

    if (order_a && order_b) {
        if (*order_a < *order_b) {
            return true;
        }
        if (*order_a > *order_b) {
            return false;
        }
    }

    return strcmp(a->name, b->name) <= 0;
}