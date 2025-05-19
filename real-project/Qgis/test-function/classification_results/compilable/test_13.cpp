#include <bits/stdc++.h>

class QString {
public:
    QString toLower() const;
};

bool operator<(const QString& a, const QString& b);

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool _compareEncodings(const QString &s1, const QString &s2) {
    return s1.toLower() < s2.toLower();
}

void test1(QString a, QString b, QString c){
    NewTest();
    if (!_compareEncodings(a,b) && !_compareEncodings(b,c) && _compareEncodings(a,c))
        ConsistencyChecker();
}

void test2(QString a, QString b, QString c){
    NewTest();
    if (_compareEncodings(a,b) && _compareEncodings(b,c) && _compareEncodings(c,a))
        TransiveChecker();
}

void test3_1(QString a, QString b){
    NewTest();
    if (_compareEncodings(a,b) && _compareEncodings(b,a))
        SymmetryChecker();
}

void test3_2(QString a, QString b){
    NewTest();
    if (_compareEncodings(a,b) && _compareEncodings(b,a))
        SymmetryChecker();
}

void test4(QString a){
    NewTest();
    if (_compareEncodings(a, a))
        ReflexivityChecker();
}