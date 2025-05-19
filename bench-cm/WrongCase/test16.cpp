//https://github.com/assimp/assimp/commit/990dc983ed2634bc764e6c4c1e6d63499eff6d58

//Violation of Anti-Reflexivity
bool compare_16(const Object* left, const Object* right) {
    return ::strncmp(left->id.name, right->id.name, std::strlen(left->id.name)) == 0;
}