#include <bits/stdc++.h>

class QgsFeatureRendererGenerator {
public:
    int level() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsFeatureRendererGenerator * g1, const QgsFeatureRendererGenerator * g2) {
    return g1->level() < g2->level();
}

void test1(const QgsFeatureRendererGenerator* a, const QgsFeatureRendererGenerator* b, const QgsFeatureRendererGenerator* c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QgsFeatureRendererGenerator* a, const QgsFeatureRendererGenerator* b, const QgsFeatureRendererGenerator* c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QgsFeatureRendererGenerator* a, const QgsFeatureRendererGenerator* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QgsFeatureRendererGenerator* a, const QgsFeatureRendererGenerator* b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QgsFeatureRendererGenerator* a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}