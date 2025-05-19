
#include <bits/stdc++.h>

namespace Qt {
    enum CaseSensitivity { CaseInsensitive, CaseSensitive };
}

class QString {
public:
    int compare(const QString& other, Qt::CaseSensitivity cs) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QString &a, const QString &b) {
    return a.compare( b, Qt::CaseInsensitive ) < 0;
}

void test1(const QString &a, const QString &b, const QString &c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QString &a, const QString &b, const QString &c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QString &a, const QString &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QString &a, const QString &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QString &a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}
