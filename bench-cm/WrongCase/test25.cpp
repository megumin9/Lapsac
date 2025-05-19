//https://github.com/scummvm/scummvm/commit/413960ac6b59d9a2c376d71b0bd43fcb6653b4a6

// Violation of Anti-Reflexivity

bool compare_25(const UpdateItem &item1, const UpdateItem &item2) {
    return (item1.priority - item2.priority < 0) ? false : true;
}