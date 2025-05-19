#include <bits/stdc++.h>
#include <QtCore/QVariant>
#include <QtCore/QMetaType>
#include <QtCore/QList>
#include <QtCore/QStringList>
#include <QtCore/QString>
#include <QtCore/QDate>
#include <QtCore/QTime>
#include <QtCore/QDateTime>
#include <QtCore/QChar>

bool qgsVariantEqual(const QVariant &a, const QVariant &b);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool qgsVariantLessThan(const QVariant &lhs, const QVariant &rhs) {
  if (!lhs.isValid())
    return rhs.isValid();
  else if (lhs.isNull())
    return rhs.isValid() && !rhs.isNull();
  else if (!rhs.isValid() || rhs.isNull())
    return false;

  switch (lhs.userType()) {
    case QMetaType::Type::Int:
      return lhs.toInt() < rhs.toInt();
    case QMetaType::Type::UInt:
      return lhs.toUInt() < rhs.toUInt();
    case QMetaType::Type::LongLong:
      return lhs.toLongLong() < rhs.toLongLong();
    case QMetaType::Type::ULongLong:
      return lhs.toULongLong() < rhs.toULongLong();
    case QMetaType::Type::Double:
      return lhs.toDouble() < rhs.toDouble();
    case QMetaType::Type::QChar:
      return lhs.toChar() < rhs.toChar();
    case QMetaType::Type::QDate:
      return lhs.toDate() < rhs.toDate();
    case QMetaType::Type::QTime:
      return lhs.toTime() < rhs.toTime();
    case QMetaType::Type::QDateTime:
      return lhs.toDateTime() < rhs.toDateTime();
    case QMetaType::Type::Bool:
      return lhs.toBool() < rhs.toBool();

    case QMetaType::Type::QVariantList: {
      const QList<QVariant> &lhsl = lhs.toList();
      const QList<QVariant> &rhsl = rhs.toList();

      int i, n = std::min(lhsl.size(), rhsl.size());
      for (i = 0; i < n && lhsl[i].userType() == rhsl[i].userType() && qgsVariantEqual(lhsl[i], rhsl[i]); i++)
        ;

      if (i == n)
        return lhsl.size() < rhsl.size();
      else
        return qgsVariantLessThan(lhsl[i], rhsl[i]);
    }

    case QMetaType::Type::QStringList: {
      const QStringList &lhsl = lhs.toStringList();
      const QStringList &rhsl = rhs.toStringList();

      int i, n = std::min(lhsl.size(), rhsl.size());
      for (i = 0; i < n && lhsl[i] == rhsl[i]; i++)
        ;

      if (i == n)
        return lhsl.size() < rhsl.size();
      else
        return lhsl[i] < rhsl[i];
    }

    default:
      return QString::localeAwareCompare(lhs.toString(), rhs.toString()) < 0;
  }
}

void test1(QVariant a, QVariant b, QVariant c) {
  NewTest();
  if (!qgsVariantLessThan(a, b) && !qgsVariantLessThan(b, c) && qgsVariantLessThan(a, c)) {
    ConsistencyChecker();
  }
}

void test2(QVariant a, QVariant b, QVariant c) {
  NewTest();
  if (qgsVariantLessThan(a, b) && qgsVariantLessThan(b, c) && qgsVariantLessThan(c, a)) {
    TransiveChecker();
  }
}

void test3_1(QVariant a, QVariant b) {
  NewTest();
  if (qgsVariantLessThan(a, b) && qgsVariantLessThan(b, a)) {
    SymmetryChecker();
  }
}

void test3_2(QVariant a, QVariant b) {
  NewTest();
  if (qgsVariantLessThan(a, b) && qgsVariantLessThan(b, a)) {
    SymmetryChecker();
  }
}

void test4(QVariant a) {
  NewTest();
  if (qgsVariantLessThan(a, a)) {
    ReflexivityChecker();
  }
}