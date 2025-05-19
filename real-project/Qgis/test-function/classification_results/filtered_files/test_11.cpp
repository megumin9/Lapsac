#include <bits/stdc++.h>

class QString {
public:
    static int localeAwareCompare(const QString& s1, const QString& s2);
};

class QgsRendererCategory {
public:
    QString label() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool labelLessThan(const QgsRendererCategory &c1, const QgsRendererCategory &c2) {
    return QString::localeAwareCompare(c1.label(), c2.label()) < 0;
}

void test1(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c) {
    NewTest();
    if (!labelLessThan(a,b) && !labelLessThan(b,c) && labelLessThan(a,c))
        ConsistencyChecker();
}

void test2(const QgsRendererCategory &a, const QgsRendererCategory &b, const QgsRendererCategory &c) {
    NewTest();
    if (labelLessThan(a,b) && labelLessThan(b,c) && labelLessThan(c,a))
        TransiveChecker();
}

void test3_1(const QgsRendererCategory &a, const QgsRendererCategory &b) {
    NewTest();
    if (labelLessThan(a,b) && labelLessThan(b,a))
        SymmetryChecker();
}

void test3_2(const QgsRendererCategory &a, const QgsRendererCategory &b) {
    NewTest();
    if (labelLessThan(a,b) && labelLessThan(b,a))
        SymmetryChecker();
}

void test4(const QgsRendererCategory &a) {
    NewTest();
    if (labelLessThan(a,a))
        ReflexivityChecker();
}