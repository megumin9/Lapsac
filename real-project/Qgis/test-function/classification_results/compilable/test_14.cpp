#include <bits/stdc++.h>

class QString {
public:
    static int localeAwareCompare(const QString& a, const QString& b);
};

class QgsDataItem {
public:
    QString name() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmpByDataItemName_(QgsDataItem *a, QgsDataItem *b) {
  return QString::localeAwareCompare( a->name(), b->name() ) < 0;
}

void test1(QgsDataItem *a,QgsDataItem *b,QgsDataItem *c){
NewTest();
if (!cmpByDataItemName_(a,b) &&!cmpByDataItemName_(b,c) && cmpByDataItemName_(a,c))
ConsistencyChecker();
}

void test2(QgsDataItem *a,QgsDataItem *b,QgsDataItem *c){
NewTest();
if (cmpByDataItemName_(a,b) && cmpByDataItemName_(b,c) && cmpByDataItemName_(c,a))
TransiveChecker();
}

void test3_1(QgsDataItem *a,QgsDataItem *b){
NewTest();
if (cmpByDataItemName_(a,b) && cmpByDataItemName_(b,a))
SymmetryChecker();
}

void test3_2(QgsDataItem *a,QgsDataItem *b){
NewTest();
if (cmpByDataItemName_(a,b) && cmpByDataItemName_(b,a))
SymmetryChecker();
}

void test4(QgsDataItem *a){
NewTest();
if (cmpByDataItemName_(a, a))
ReflexivityChecker();
}