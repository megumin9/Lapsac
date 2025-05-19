#include <bits/stdc++.h>

enum class PrimitiveType { Line };
struct PrimitiveData { double z; PrimitiveType type; };

bool qgsDoubleNear(double, double, double);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const PrimitiveData & a, const PrimitiveData & b) {
    if ( qgsDoubleNear( a.z, b.z, 0.001 ) )
    {
      
      if ( a.type == PrimitiveType::Line )
        return false;
      else if ( b.type == PrimitiveType::Line )
        return true;
    }
    return a.z < b.z;
}

void test1(PrimitiveData a, PrimitiveData b, PrimitiveData c){
NewTest();
if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
ConsistencyChecker();
}

void test2(PrimitiveData a, PrimitiveData b, PrimitiveData c){
NewTest();
if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
TransiveChecker();
}

void test3_1(PrimitiveData a, PrimitiveData b){
NewTest();
if (lambda0(a,b) && lambda0(b,a))
SymmetryChecker();
}

void test4(PrimitiveData a){
NewTest();
if (lambda0(a, a))
ReflexivityChecker();
}