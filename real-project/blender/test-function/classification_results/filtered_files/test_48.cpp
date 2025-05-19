
#include <bits/stdc++.h>
struct NSVGedge {
    int y0;
};
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int nsvg__cmpEdge(const void *p, const void *q) {
	const NSVGedge* a = (const NSVGedge*)p;
	const NSVGedge* b = (const NSVGedge*)q;

	if (a->y0 < b->y0) return -1;
	if (a->y0 > b->y0) return  1;
	return 0;
}

void test1(NSVGedge* a, NSVGedge* b, NSVGedge* c){
NewTest();
if (!(nsvg__cmpEdge(a,b)<0) && !(nsvg__cmpEdge(b,c)<0) && (nsvg__cmpEdge(a,c)<0))
ConsistencyChecker();
}

void test2(NSVGedge* a, NSVGedge* b, NSVGedge* c){
NewTest();
if ((nsvg__cmpEdge(a,b)<0) && (nsvg__cmpEdge(b,c)<0) && (nsvg__cmpEdge(c,a)<0)) 
TransiveChecker();
}

void test3_1(NSVGedge* a, NSVGedge* b){
NewTest();
if ((nsvg__cmpEdge(a,b)>0)&&(nsvg__cmpEdge(b,a)>0))
SymmetryChecker();
}

void test3_2(NSVGedge* a, NSVGedge* b){
NewTest();
if ((nsvg__cmpEdge(a,b)<0)&&(nsvg__cmpEdge(b,a)<0))
SymmetryChecker();
}

void test4(NSVGedge* a){
NewTest();
if (nsvg__cmpEdge(a, a)<0||nsvg__cmpEdge(a, a)>0) 
ReflexivityChecker();
}
