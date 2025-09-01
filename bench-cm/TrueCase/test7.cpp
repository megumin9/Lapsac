// https://github.com/vcmi/vcmi/commit/0782ee7689e89393baff6ebf6e1552bb12bdb3f2

bool compare_7(const std::string& lesser, const std::string& greater) {
    return CModEntry::compareVersions(lesser, greater);  
}
