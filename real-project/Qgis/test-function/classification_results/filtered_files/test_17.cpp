#include <bits/stdc++.h>

class QString {
public:
    static int localeAwareCompare(const QString& a, const QString& b);
};

class QAction {
public:
    QString text() const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool cmpByText_(QAction *a, QAction *b) {
  return QString::localeAwareCompare( a->text(), b->text() ) < 0;
}

void test1(QAction *a, QAction *b, QAction *c) {
  NewTest();
  if (!cmpByText_(a,b) && !cmpByText_(b,c) && cmpByText_(a,c))
    ConsistencyChecker();
}

void test2(QAction *a, QAction *b, QAction *c) {
  NewTest();
  if (cmpByText_(a,b) && cmpByText_(b,c) && cmpByText_(c,a))
    TransiveChecker();
}

void test3_1(QAction *a, QAction *b) {
  NewTest();
  if (cmpByText_(a,b) && cmpByText_(b,a))
    SymmetryChecker();
}

void test3_2(QAction *a, QAction *b) {
  NewTest();
  if (cmpByText_(a,b) && cmpByText_(b,a))
    SymmetryChecker();
}

void test4(QAction *a) {
  NewTest();
  if (cmpByText_(a, a))
    ReflexivityChecker();
}