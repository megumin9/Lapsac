
#include <bits/stdc++.h>

class QString {
public:
    int localeAwareCompare(const QString&) const;
};

struct QgsFeatureExpressionValuesGatherer {
    struct Entry {
        QString value;
    };
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsFeatureExpressionValuesGatherer::Entry & a, const QgsFeatureExpressionValuesGatherer::Entry & b) {
    return a.value.localeAwareCompare( b.value ) < 0;
}

void test1(const QgsFeatureExpressionValuesGatherer::Entry& a, const QgsFeatureExpressionValuesGatherer::Entry& b, const QgsFeatureExpressionValuesGatherer::Entry& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QgsFeatureExpressionValuesGatherer::Entry& a, const QgsFeatureExpressionValuesGatherer::Entry& b, const QgsFeatureExpressionValuesGatherer::Entry& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QgsFeatureExpressionValuesGatherer::Entry& a, const QgsFeatureExpressionValuesGatherer::Entry& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QgsFeatureExpressionValuesGatherer::Entry& a, const QgsFeatureExpressionValuesGatherer::Entry& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QgsFeatureExpressionValuesGatherer::Entry& a) {
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}
