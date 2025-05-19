#include <bits/stdc++.h>
#include <memory>
#include <utility>
#include <QString>

class QgsAnnotationItem {
public:
    int zIndex() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& a, 
            const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& b) {
    return a.second->zIndex() < b.second->zIndex();
}

void test1(const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& a, 
          const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& b, 
          const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& a, 
          const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& b, 
          const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& a, 
            const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(const std::pair<QString, std::unique_ptr<QgsAnnotationItem>>& a) {
    NewTest();
    if (lambda0(a,a))
        ReflexivityChecker();
}