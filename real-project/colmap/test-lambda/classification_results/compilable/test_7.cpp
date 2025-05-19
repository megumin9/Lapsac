#include <vector>
#include <cstddef>

struct Vector3d {
    int x, y, z;
};

bool LowerVector3d(const Vector3d& a, const Vector3d& b);
std::vector<Vector3d> points3D;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(size_t i, size_t j) {
  return LowerVector3d(points3D[i], points3D[j]);
}

void test1(size_t a, size_t b, size_t c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c)) 
ConsistencyChecker();
}

void test2(size_t a, size_t b, size_t c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a)) 
TransiveChecker();
}

void test3_1(size_t a, size_t b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(size_t a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}