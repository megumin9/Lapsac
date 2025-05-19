#include <bits/stdc++.h>

namespace Qt {
enum CaseSensitivity { CaseInsensitive };
}

class QString {
public:
    int compare(const QString& other, Qt::CaseSensitivity) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda2(const QString &a, const QString &b) {
    return a.compare( b, Qt::CaseInsensitive ) < 0;
}

void test1(QString a,QString b,QString c){
NewTest();
if (!lambda2(a,b) && !lambda2(b,c) && lambda2(a,c))
ConsistencyChecker();
}

void test2(QString a,QString b,QString c){
NewTest();
if (lambda2(a,b) && lambda2(b,c) && lambda2(c,a)) 
TransiveChecker();
}

void test3_1(QString a,QString b){
NewTest();
if (lambda2(a,b) && lambda2(b,a))
SymmetryChecker();
}

void test4(QString a){
NewTest();
if (lambda2(a, a))
ReflexivityChecker();
}