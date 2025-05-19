#include <bits/stdc++.h>

struct InstrumentTemplate {
    bool drumset;
    std::vector<int> genres;
};

int findMaxPitchDiff(int& minMaxPitch, const InstrumentTemplate* templ);
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool compare_15(const InstrumentTemplate* templ1, const InstrumentTemplate* templ2) {
    int minMaxPitch; 
    const int diff1 = findMaxPitchDiff(minMaxPitch, templ1);
    const int diff2 = findMaxPitchDiff(minMaxPitch, templ2);

    if (diff1 != diff2) {
        return diff1 < diff2;
    }

    if (templ1->drumset && !templ2->drumset) {
        return true;
    }

    return templ1->genres.size() > templ2->genres.size();
}

void test1(const InstrumentTemplate* a, const InstrumentTemplate* b, const InstrumentTemplate* c) {
    NewTest();
    if (!compare_15(a,b) && !compare_15(b,c) && compare_15(a,c))
        ConsistencyChecker();
}

void test2(const InstrumentTemplate* a, const InstrumentTemplate* b, const InstrumentTemplate* c) {
    NewTest();
    if (compare_15(a,b) && compare_15(b,c) && compare_15(c,a))
        TransiveChecker();
}

void test3_1(const InstrumentTemplate* a, const InstrumentTemplate* b) {
    NewTest();
    if (compare_15(a,b) && compare_15(b,a))
        SymmetryChecker();
}

void test3_2(const InstrumentTemplate* a, const InstrumentTemplate* b) {
    NewTest();
    if (compare_15(a,b) && compare_15(b,a))
        SymmetryChecker();
}

void test4(const InstrumentTemplate* a) {
    NewTest();
    if (compare_15(a, a))
        ReflexivityChecker();
}