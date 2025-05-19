#include <bits/stdc++.h>

namespace Qgis {
    enum class QueryStorageBackend {
        CurrentProject
    };
}

class QString {
public:
    static int localeAwareCompare(const QString &a, const QString &b);
};

struct QueryDetails {
    QString name;
    Qgis::QueryStorageBackend backend;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QueryDetails &a, const QueryDetails &b)
{
    if ( QString::localeAwareCompare(a.name, b.name) == 0 )
        return a.backend == Qgis::QueryStorageBackend::CurrentProject;
    return QString::localeAwareCompare( a.name, b.name ) < 0;
}

void test1(const QueryDetails &a, const QueryDetails &b, const QueryDetails &c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const QueryDetails &a, const QueryDetails &b, const QueryDetails &c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const QueryDetails &a, const QueryDetails &b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const QueryDetails &a){
    NewTest();
    if (lambda0(a, a))
        ReflexivityChecker();
}