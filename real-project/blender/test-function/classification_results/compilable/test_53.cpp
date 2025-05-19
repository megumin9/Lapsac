#include <bits/stdc++.h>
void NewTest();
void ConsistencyChecker();
void TransiveChecker();
void SymmetryChecker();
void ReflexivityChecker();

int compare_double_fn(const void *a_, const void *b_) {
	const double *a = static_cast<const double*>(a_);
	const double *b = static_cast<const double*>(b_);
	if      (*a > *b) return  1;
	else if (*a < *b) return -1;
	else              return  0;
}

void test1(double *a, double *b, double *c){
	NewTest();
	if (!(compare_double_fn(a,b)<0) && !(compare_double_fn(b,c)<0) && (compare_double_fn(a,c)<0))
		ConsistencyChecker();
}

void test2(double *a, double *b, double *c){
	NewTest();
	if ((compare_double_fn(a,b)<0) && (compare_double_fn(b,c)<0) && (compare_double_fn(c,a)<0))
		TransiveChecker();
}

void test3_1(double *a, double *b){
	NewTest();
	if ((compare_double_fn(a,b)>0)&&(compare_double_fn(b,a)>0))
		SymmetryChecker();
}

void test3_2(double *a, double *b){
	NewTest();
	if ((compare_double_fn(a,b)<0)&&(compare_double_fn(b,a)<0))
		SymmetryChecker();
}

void test4(double *a){
	NewTest();
	if (compare_double_fn(a,a)<0||compare_double_fn(a,a)>0)
		ReflexivityChecker();
}