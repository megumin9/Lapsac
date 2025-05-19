
#include <bits/stdc++.h>

enum MyItemColumnID {
    MyItemColumnID_ID,
    MyItemColumnID_Name,
    MyItemColumnID_Quantity,
    MyItemColumnID_Description
};

enum ImGuiSortDirection {
    ImGuiSortDirection_Ascending,
    ImGuiSortDirection_Descending
};

struct ImGuiTableColumnSortSpecs {
    MyItemColumnID ColumnUserID;
    ImGuiSortDirection SortDirection;
};

struct ImGuiTableSortSpecs {
    ImGuiTableColumnSortSpecs* Specs;
    int SpecsCount;
};

struct MyItem {
    int ID;
    const char* Name;
    int Quantity;
    const char* Description;
};

extern ImGuiTableSortSpecs* s_current_sort_specs;

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int CompareWithSortSpecs(const void* lhs, const void* rhs) {
    const MyItem* a = (const MyItem*)lhs;
    const MyItem* b = (const MyItem*)rhs;
    for (int n = 0; n < s_current_sort_specs->SpecsCount; n++) {
        const ImGuiTableColumnSortSpecs* sort_spec = &s_current_sort_specs->Specs[n];
        int delta = 0;
        switch (sort_spec->ColumnUserID) {
        case MyItemColumnID_ID:             delta = (a->ID - b->ID);                break;
        case MyItemColumnID_Name:           delta = (strcmp(a->Name, b->Name));     break;
        case MyItemColumnID_Quantity:       delta = (a->Quantity - b->Quantity);    break;
        case MyItemColumnID_Description:    delta = (strcmp(a->Name, b->Name));     break;
        default: ; // IM_ASSERT(0); 
        }
        if (delta > 0)
            return (sort_spec->SortDirection == ImGuiSortDirection_Ascending) ? +1 : -1;
        if (delta < 0)
            return (sort_spec->SortDirection == ImGuiSortDirection_Ascending) ? -1 : +1;
    }
    return (a->ID - b->ID);
}

void test1(const MyItem* a, const MyItem* b, const MyItem* c) {
    NewTest();
    if (!(CompareWithSortSpecs(a, b) < 0) && !(CompareWithSortSpecs(b, c) < 0) && (CompareWithSortSpecs(a, c) < 0))
        ConsistencyChecker();
}

void test2(const MyItem* a, const MyItem* b, const MyItem* c) {
    NewTest();
    if ((CompareWithSortSpecs(a, b) < 0) && (CompareWithSortSpecs(b, c) < 0) && (CompareWithSortSpecs(c, a) < 0))
        TransiveChecker();
}

void test3_1(const MyItem* a, const MyItem* b) {
    NewTest();
    if ((CompareWithSortSpecs(a, b) > 0) && (CompareWithSortSpecs(b, a) > 0))
        SymmetryChecker();
}

void test3_2(const MyItem* a, const MyItem* b) {
    NewTest();
    if ((CompareWithSortSpecs(a, b) < 0) && (CompareWithSortSpecs(b, a) < 0))
        SymmetryChecker();
}

void test4(const MyItem* a) {
    NewTest();
    if (CompareWithSortSpecs(a, a) < 0 || CompareWithSortSpecs(a, a) > 0)
        ReflexivityChecker();
}
