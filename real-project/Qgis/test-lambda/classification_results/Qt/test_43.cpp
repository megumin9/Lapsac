#include <QtCore/QString>
#include <QtCore>

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QString &a, const QString &b)
{
    return a.compare( b, Qt::CaseInsensitive ) < 0;
}

void test1(QString a, QString b, QString c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(QString a, QString b, QString c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(QString a, QString b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(QString a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}