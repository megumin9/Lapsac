// https://github.com/JetBrains/intellij-community/commit/80e9433297f3b08393b835bc38aa635b7ded6f2b

// Violation of Anti-Symmetry 


int compare_31(const void* o1, const void* o2) {
    if (o1 == o2) return 0;
    if (o1 == &NullUsage::INSTANCE || o1 == nullptr) return -1;
    if (o2 == &NullUsage::INSTANCE || o2 == nullptr) return 1;
    
    int c = compareByFileAndOffset(o1, o2);
    if (c != 0) return c;

    std::string str1 = *static_cast<const std::string*>(o1);
    std::string str2 = *static_cast<const std::string*>(o2);
    return str1.compare(str2);
}
