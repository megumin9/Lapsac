#include <bits/stdc++.h>

class QVariant;
bool qgsVariantLessThan(const QVariant &lhs, const QVariant &rhs);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool qgsVariantGreaterThan( const QVariant &lhs, const QVariant &rhs )
{
    return ! qgsVariantLessThan( lhs, rhs );
}

void test1(const QVariant &a, const QVariant &b, const QVariant &c){
    NewTest();
    if (!qgsVariantGreaterThan(a,b) && !qgsVariantGreaterThan(b,c) && qgsVariantGreaterThan(a,c))
        ConsistencyChecker();
}

void test2(const QVariant &a, const QVariant &b, const QVariant &c){
    NewTest();
    if (qgsVariantGreaterThan(a,b) && qgsVariantGreaterThan(b,c) && qgsVariantGreaterThan(c,a))
        TransiveChecker();
}

void test3_1(const QVariant &a, const QVariant &b){
    NewTest();
    if (qgsVariantGreaterThan(a,b) && qgsVariantGreaterThan(b,a))
        SymmetryChecker();
}

void test3_2(const QVariant &a, const QVariant &b){
    NewTest();
    if (qgsVariantGreaterThan(a,b) && qgsVariantGreaterThan(b,a))
        SymmetryChecker();
}

void test4(const QVariant &a){
    NewTest();
    if (qgsVariantGreaterThan(a, a))
        ReflexivityChecker();
}