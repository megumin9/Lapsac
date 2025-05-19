
#include <bits/stdc++.h>

class QgsModelComponentGraphicItem {
public:
    virtual ~QgsModelComponentGraphicItem() = default;
};

class QgsModelCommentGraphicItem : public QgsModelComponentGraphicItem {};
class QgsModelGroupBoxGraphicItem : public QgsModelComponentGraphicItem {};
class QgsModelOutputGraphicItem : public QgsModelComponentGraphicItem {};
class QgsModelChildAlgorithmGraphicItem : public QgsModelComponentGraphicItem {};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(QgsModelComponentGraphicItem *p1, QgsModelComponentGraphicItem *p2) {
    if ( dynamic_cast<QgsModelCommentGraphicItem *>( p1 ) )
      return true;
    else if ( dynamic_cast<QgsModelCommentGraphicItem *>( p2 ) )
      return false;
    else if ( dynamic_cast<QgsModelGroupBoxGraphicItem *>( p1 ) )
      return true;
    else if ( dynamic_cast<QgsModelGroupBoxGraphicItem *>( p2 ) )
      return false;
    else if ( dynamic_cast<QgsModelOutputGraphicItem *>( p1 ) )
      return true;
    else if ( dynamic_cast<QgsModelOutputGraphicItem *>( p2 ) )
      return false;
    else if ( dynamic_cast<QgsModelChildAlgorithmGraphicItem *>( p1 ) )
      return true;
    else if ( dynamic_cast<QgsModelChildAlgorithmGraphicItem *>( p2 ) )
      return false;
    return false;
}

void test1(QgsModelComponentGraphicItem *a, QgsModelComponentGraphicItem *b, QgsModelComponentGraphicItem *c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
        ConsistencyChecker();
    }
}

void test2(QgsModelComponentGraphicItem *a, QgsModelComponentGraphicItem *b, QgsModelComponentGraphicItem *c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
        TransiveChecker();
    }
}

void test3_1(QgsModelComponentGraphicItem *a, QgsModelComponentGraphicItem *b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test3_2(QgsModelComponentGraphicItem *a, QgsModelComponentGraphicItem *b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test4(QgsModelComponentGraphicItem *a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}
