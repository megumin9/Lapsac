#include <bits/stdc++.h>

class QString {
public:
    static int localeAwareCompare(const QString& s1, const QString& s2);
};

class QgsRendererRange {
public:
    QString label() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool labelLessThan(const QgsRendererRange &r1, const QgsRendererRange &r2) {
    return QString::localeAwareCompare(r1.label(), r2.label()) < 0;
}

void test1(QgsRendererRange a, QgsRendererRange b, QgsRendererRange c) {
    NewTest();
    if (!labelLessThan(a, b) && !labelLessThan(b, c) && labelLessThan(a, c))
        ConsistencyChecker();
}

void test2(QgsRendererRange a, QgsRendererRange b, QgsRendererRange c) {
    NewTest();
    if (labelLessThan(a, b) && labelLessThan(b, c) && labelLessThan(c, a))
        TransiveChecker();
}

void test3_1(QgsRendererRange a, QgsRendererRange b) {
    NewTest();
    if (labelLessThan(a, b) && labelLessThan(b, a))
        SymmetryChecker();
}

void test4(QgsRendererRange a) {
    NewTest();
    if (labelLessThan(a, a))
        ReflexivityChecker();
}