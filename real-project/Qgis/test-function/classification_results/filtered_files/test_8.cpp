#include <bits/stdc++.h>
using namespace std;

struct QgsRendererRange;

bool labelLessThan(const QgsRendererRange &r1, const QgsRendererRange &r2);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool labelGreaterThan( const QgsRendererRange &r1, const QgsRendererRange &r2 )
{
    return !labelLessThan( r1, r2 );
}

void test1(const QgsRendererRange &a, const QgsRendererRange &b, const QgsRendererRange &c){
NewTest();
if (!labelGreaterThan(a,b) && !labelGreaterThan(b,c) && labelGreaterThan(a,c)) 
ConsistencyChecker();
}

void test2(const QgsRendererRange &a, const QgsRendererRange &b, const QgsRendererRange &c){
NewTest();
if (labelGreaterThan(a,b) && labelGreaterThan(b,c) && labelGreaterThan(c,a)) 
TransiveChecker();
}

void test3_1(const QgsRendererRange &a, const QgsRendererRange &b){
NewTest();
if (labelGreaterThan(a,b) && labelGreaterThan(b,a))
SymmetryChecker();
}

void test3_2(const QgsRendererRange &a, const QgsRendererRange &b){
NewTest();
if (labelGreaterThan(a,b) && labelGreaterThan(b,a))
SymmetryChecker();
}

void test4(const QgsRendererRange &a){
NewTest();
if (labelGreaterThan(a, a)) 
ReflexivityChecker();
}