//https://github.com/mysql/mysql-server/commit/cdbdd7a1755bcf4611d0b095d5bd3fffd180f7fa

// Violation of Anti-Reflexivity

bool compare_2(const MyStruct& p1, const MyStruct& p2) {
    return p1.first.compare(p2.first) <= 0;
}