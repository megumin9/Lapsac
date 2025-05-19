#include <bits/stdc++.h>
using namespace std;

struct QgsRendererCategory {
    int value() const;
};

bool qgsVariantGreaterThan(int a, int b);

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool valueGreaterThan( const QgsRendererCategory &c1, const QgsRendererCategory &c2 )
{
    return qgsVariantGreaterThan( c1.value(), c2.value() );
}

void test1(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c){
NewTest();
if (!valueGreaterThan(a,b) && !valueGreaterThan(b,c) && valueGreaterThan(a,c)) 
ConsistencyChecker();
}

void test2(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c){
NewTest();
if (valueGreaterThan(a,b) && valueGreaterThan(b,c) && valueGreaterThan(c,a)) 
TransiveChecker();
}

void test3_1(const QgsRendererCategory &a, const QgsRendererCategory &b){
NewTest();
if (valueGreaterThan(a,b) && valueGreaterThan(b,a))
SymmetryChecker();
}

void test4(const QgsRendererCategory &a){
NewTest();
if (valueGreaterThan(a, a))
ReflexivityChecker();
}