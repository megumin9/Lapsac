#include <bits/stdc++.h>
using namespace std;

struct QgsRendererCategory {
    int value() const;
};

bool qgsVariantLessThan(int a, int b);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool valueLessThan( const QgsRendererCategory &c1, const QgsRendererCategory &c2 )
{
    return qgsVariantLessThan( c1.value(), c2.value() );
}

void test1(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c){
    NewTest();
    if (!valueLessThan(a,b) && !valueLessThan(b,c) && valueLessThan(a,c))
    ConsistencyChecker();
}

void test2(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c){
    NewTest();
    if (valueLessThan(a,b) && valueLessThan(b,c) && valueLessThan(c,a))
    TransiveChecker();
}

void test3_1(const QgsRendererCategory &a, const QgsRendererCategory &b){
    NewTest();
    if (valueLessThan(a,b) && valueLessThan(b,a))
    SymmetryChecker();
}

void test4(const QgsRendererCategory &a){
    NewTest();
    if (valueLessThan(a, a))
    ReflexivityChecker();
}