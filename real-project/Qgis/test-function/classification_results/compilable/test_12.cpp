
#include <bits/stdc++.h>

struct QgsRendererCategory;

bool labelLessThan(const QgsRendererCategory &c1, const QgsRendererCategory &c2);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool labelGreaterThan(const QgsRendererCategory &c1, const QgsRendererCategory &c2)
{
    return !labelLessThan( c1, c2 );
}

void test1(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c){
    NewTest();
    if (!labelGreaterThan(a,b) && !labelGreaterThan(b,c) && labelGreaterThan(a,c))
    ConsistencyChecker();
}

void test2(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c){
    NewTest();
    if (labelGreaterThan(a,b) && labelGreaterThan(b,c) && labelGreaterThan(c,a))
    TransiveChecker();
}

void test3_1(const QgsRendererCategory &a, const QgsRendererCategory &b){
    NewTest();
    if (labelGreaterThan(a,b) && labelGreaterThan(b,a))
    SymmetryChecker();
}

void test3_2(const QgsRendererCategory &a, const QgsRendererCategory &b){
    NewTest();
    if (labelGreaterThan(a,b) && labelGreaterThan(b,a))
    SymmetryChecker();
}

void test4(const QgsRendererCategory &a){
    NewTest();
    if (labelGreaterThan(a, a))
    ReflexivityChecker();
}
