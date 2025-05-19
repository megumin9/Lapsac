#include <bits/stdc++.h>
struct BreakListEntry {
    int lowLimit;
};
class DrawBrokenView {
public:
    static bool breakLess(const BreakListEntry& entry0, const BreakListEntry& entry1);
};
bool DrawBrokenView::breakLess(const BreakListEntry& entry0, const BreakListEntry& entry1) {
    return (entry0.lowLimit < entry1.lowLimit);
}
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();
void test1(BreakListEntry a, BreakListEntry b, BreakListEntry c) {
    NewTest();
    if (!DrawBrokenView::breakLess(a,b) && !DrawBrokenView::breakLess(b,c) && DrawBrokenView::breakLess(a,c))
    ConsistencyChecker();
}
void test2(BreakListEntry a, BreakListEntry b, BreakListEntry c) {
    NewTest();
    if (DrawBrokenView::breakLess(a,b) && DrawBrokenView::breakLess(b,c) && DrawBrokenView::breakLess(c,a))
    TransiveChecker();
}
void test3_1(BreakListEntry a, BreakListEntry b) {
    NewTest();
    if (DrawBrokenView::breakLess(a,b) && DrawBrokenView::breakLess(b,a))
    SymmetryChecker();
}
void test3_2(BreakListEntry a, BreakListEntry b) {
    NewTest();
    if (DrawBrokenView::breakLess(a,b) && DrawBrokenView::breakLess(b,a))
    SymmetryChecker();
}
void test4(BreakListEntry a) {
    NewTest();
    if (DrawBrokenView::breakLess(a, a))
    ReflexivityChecker();
}