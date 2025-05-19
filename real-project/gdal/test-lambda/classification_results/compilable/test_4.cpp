#include <bits/stdc++.h>
using namespace std;

enum OGRFieldType {
    OFTString,
    OFTInteger,
    OFTInteger64,
    OFTReal,
    OFTDate,
    OFTDateTime
};

struct OGRField {
    struct {
        int Year, Month, Day, Hour, Minute, Second;
    } Date;
};

class OGRFeature {
public:
    bool IsFieldSetAndNotNull(int) const;
    const char* GetFieldAsString(int) const;
    long long GetFieldAsInteger64(int) const;
    double GetFieldAsDouble(int) const;
    const OGRField* GetRawFieldRef(int) const;
    long long GetFID() const;
};

struct SourceDesc {
    OGRFeature* poFeature;
};

extern bool m_bSortFieldAsc;
extern int m_nSortFieldIndex;
extern OGRFieldType eFieldType;
#define CPLAssert(expr) assert(expr)

void NewTest();
void ConsistencyChecker();
void TransitiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool lambda0(const SourceDesc &a, const SourceDesc &b) {
    OGRFeature* const &poFeatureA = (m_bSortFieldAsc ? a : b).poFeature;
    OGRFeature* const &poFeatureB = (m_bSortFieldAsc ? b : a).poFeature;
    if (m_nSortFieldIndex >= 0 &&
        poFeatureA->IsFieldSetAndNotNull(m_nSortFieldIndex) &&
        poFeatureB->IsFieldSetAndNotNull(m_nSortFieldIndex)) {
        if (eFieldType == OFTString) {
            const int nCmp = strcmp(poFeatureA->GetFieldAsString(m_nSortFieldIndex),
                                    poFeatureB->GetFieldAsString(m_nSortFieldIndex));
            if (nCmp < 0) return true;
            if (nCmp > 0) return false;
        } else if (eFieldType == OFTInteger || eFieldType == OFTInteger64) {
            const long long nA = poFeatureA->GetFieldAsInteger64(m_nSortFieldIndex);
            const long long nB = poFeatureB->GetFieldAsInteger64(m_nSortFieldIndex);
            if (nA < nB) return true;
            if (nA > nB) return false;
        } else if (eFieldType == OFTReal) {
            const double dfA = poFeatureA->GetFieldAsDouble(m_nSortFieldIndex);
            const double dfB = poFeatureB->GetFieldAsDouble(m_nSortFieldIndex);
            if (dfA < dfB) return true;
            if (dfA > dfB) return false;
        } else if (eFieldType == OFTDate || eFieldType == OFTDateTime) {
            const OGRField* poFieldA = poFeatureA->GetRawFieldRef(m_nSortFieldIndex);
            const OGRField* poFieldB = poFeatureB->GetRawFieldRef(m_nSortFieldIndex);
            #define COMPARE_DATE_COMPONENT(comp) \
                do { \
                    if (poFieldA->Date.comp < poFieldB->Date.comp) return true; \
                    if (poFieldA->Date.comp > poFieldB->Date.comp) return false; \
                } while (0)
            COMPARE_DATE_COMPONENT(Year);
            COMPARE_DATE_COMPONENT(Month);
            COMPARE_DATE_COMPONENT(Day);
            COMPARE_DATE_COMPONENT(Hour);
            COMPARE_DATE_COMPONENT(Minute);
            COMPARE_DATE_COMPONENT(Second);
            #undef COMPARE_DATE_COMPONENT
        } else {
            CPLAssert(false);
        }
    }
    return poFeatureA->GetFID() < poFeatureB->GetFID();
}

void test1(SourceDesc a, SourceDesc b, SourceDesc c) {
    NewTest();
    if (!lambda0(a, b) && !lambda0(b, c) && lambda0(a, c)) {
        ConsistencyChecker();
    }
}

void test2(SourceDesc a, SourceDesc b, SourceDesc c) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, c) && lambda0(c, a)) {
        TransitiveChecker();
    }
}

void test3_1(SourceDesc a, SourceDesc b) {
    NewTest();
    if (lambda0(a, b) && lambda0(b, a)) {
        SymmetryChecker();
    }
}

void test4(SourceDesc a) {
    NewTest();
    if (lambda0(a, a)) {
        ReflexivityChecker();
    }
}