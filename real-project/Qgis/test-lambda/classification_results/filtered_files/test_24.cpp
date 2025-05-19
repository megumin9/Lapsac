#include <bits/stdc++.h>

class QFile {
public:
    enum FileTime { FileAccessTime, FileBirthTime };
};

class QDateTime {
public:
    bool isValid() const;
    bool operator>(const QDateTime& other) const;
};

class QFileInfo {
public:
    QDateTime fileTime(QFile::FileTime type) const;
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(QFileInfo &f1, QFileInfo &f2) {
    QDateTime t1 = f1.fileTime(QFile::FileTime::FileAccessTime);
    if (!t1.isValid())
        t1 = f1.fileTime(QFile::FileTime::FileBirthTime);
    QDateTime t2 = f2.fileTime(QFile::FileTime::FileAccessTime);
    if (!t2.isValid())
        t2 = f2.fileTime(QFile::FileTime::FileBirthTime);
    return t1 > t2;
}

void test1(QFileInfo a, QFileInfo b, QFileInfo c) {
    NewTest();
    if (!lambda0(a,b) && !lambda0(b,c) && lambda0(a,c))
        ConsistencyChecker();
}

void test2(QFileInfo a, QFileInfo b, QFileInfo c) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,c) && lambda0(c,a))
        TransiveChecker();
}

void test3_1(QFileInfo a, QFileInfo b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test3_2(QFileInfo a, QFileInfo b) {
    NewTest();
    if (lambda0(a,b) && lambda0(b,a))
        SymmetryChecker();
}

void test4(QFileInfo a) {
    NewTest();
    if (lambda0(a,a))
        ReflexivityChecker();
}