#include <QtCore/QString>
namespace QgsGdalUtils { struct VsiNetworkFileSystemDetails { QString name; }; }
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const QgsGdalUtils::VsiNetworkFileSystemDetails & a, const QgsGdalUtils::VsiNetworkFileSystemDetails & b) {
    return QString::localeAwareCompare( a.name, b.name ) < 0;
}

void test1(const QgsGdalUtils::VsiNetworkFileSystemDetails& a, const QgsGdalUtils::VsiNetworkFileSystemDetails& b, const QgsGdalUtils::VsiNetworkFileSystemDetails& c){
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
    ConsistencyChecker();
}

void test2(const QgsGdalUtils::VsiNetworkFileSystemDetails& a, const QgsGdalUtils::VsiNetworkFileSystemDetails& b, const QgsGdalUtils::VsiNetworkFileSystemDetails& c){
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
    TransiveChecker();
}

void test3_1(const QgsGdalUtils::VsiNetworkFileSystemDetails& a, const QgsGdalUtils::VsiNetworkFileSystemDetails& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test3_2(const QgsGdalUtils::VsiNetworkFileSystemDetails& a, const QgsGdalUtils::VsiNetworkFileSystemDetails& b){
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
    SymmetryChecker();
}

void test4(const QgsGdalUtils::VsiNetworkFileSystemDetails& a){
    NewTest();
    if (lambda0(a, a))
    ReflexivityChecker();
}