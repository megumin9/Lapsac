
#include <string>

struct QgsLabelPosition {
    bool isUnplaced;
    std::string labelText;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda1(const QgsLabelPosition &a, const QgsLabelPosition &b) {
    return a.isUnplaced == b.isUnplaced ? a.labelText.compare( b.labelText ) < 0 : a.isUnplaced < b.isUnplaced;
}

void test1(const QgsLabelPosition &a, const QgsLabelPosition &b, const QgsLabelPosition &c){
    NewTest();
    if (!lambda1(a,b) && !lambda1(b,c) && lambda1(a,c))
    ConsistencyChecker();
}

void test2(const QgsLabelPosition &a, const QgsLabelPosition &b, const QgsLabelPosition &c){
    NewTest();
    if (lambda1(a,b) && lambda1(b,c) && lambda1(c,a))
    TransiveChecker();
}

void test3_1(const QgsLabelPosition &a, const QgsLabelPosition &b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test3_2(const QgsLabelPosition &a, const QgsLabelPosition &b){
    NewTest();
    if (lambda1(a,b) && lambda1(b,a))
    SymmetryChecker();
}

void test4(const QgsLabelPosition &a){
    NewTest();
    if (lambda1(a, a))
    ReflexivityChecker();
}
