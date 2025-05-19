#include <bits/stdc++.h>

struct gp_Pnt {
    double X() const;
    double Y() const;
    double Z() const;
    bool IsEqual(const gp_Pnt& other, double tol) const;
};

class Precision {
public:
    static double Confusion();
};

class ImpExpDxfWrite {
public:
    static bool gp_PntCompare(gp_Pnt p1, gp_Pnt p2);
};

void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

bool ImpExpDxfWrite::gp_PntCompare(gp_Pnt p1, gp_Pnt p2) {
    bool result = false;
    if (!(p1.IsEqual(p2, Precision::Confusion()))) {              
        if (!(fabs(p1.X() - p2.X()) < Precision::Confusion())) {  
            result = p1.X() < p2.X();
        }
        else if (!(fabs(p1.Y() - p2.Y()) < Precision::Confusion())) {  
            result = p1.Y() < p2.Y();
        }
        else {
            result = p1.Z() < p2.Z();
        }
    }
    return result;
}

void test1(gp_Pnt a, gp_Pnt b, gp_Pnt c){
    NewTest();
    if (!ImpExpDxfWrite::gp_PntCompare(a,b) && !ImpExpDxfWrite::gp_PntCompare(b,c) && ImpExpDxfWrite::gp_PntCompare(a,c)) 
        ConsistencyChecker();
}

void test2(gp_Pnt a, gp_Pnt b, gp_Pnt c){
    NewTest();
    if (ImpExpDxfWrite::gp_PntCompare(a,b) && ImpExpDxfWrite::gp_PntCompare(b,c) && ImpExpDxfWrite::gp_PntCompare(c,a)) 
        TransiveChecker();
}

void test3_1(gp_Pnt a, gp_Pnt b){
    NewTest();
    if (ImpExpDxfWrite::gp_PntCompare(a,b) && ImpExpDxfWrite::gp_PntCompare(b,a))
        SymmetryChecker();
}

void test3_2(gp_Pnt a, gp_Pnt b){
    NewTest();
    if (ImpExpDxfWrite::gp_PntCompare(a,b) && ImpExpDxfWrite::gp_PntCompare(b,a))
        SymmetryChecker();
}

void test4(gp_Pnt a){
    NewTest();
    if (ImpExpDxfWrite::gp_PntCompare(a, a)) 
        ReflexivityChecker();
}