Please generate code based on the comparison function and choose the right template, it is determined by the return value type of the function. If the type of the return value is bool, choose the left one. If the type of the return value is int, choose the right one. 

Output Format Specification
Desired format:

<The definition and the **body** of the compare function>

void test1(a,b,c){
NewTest();
if (!<function name>(a,b) &&!< function name>(b,c) && <function name>(a,c)) / if (!(<function name>(a,b)<0) && ! (<function name>(b, c)<0) && (<function name>(a,c)<0))
ConsistencyChecker();
}

void test2(a,b,c){
NewTest();
if (<function name>(a,b) && <function name>(b,c) && <function name>(c,a)) / if ((<function name>(a,b)<0) && (<function name>(b,c)<0) && (<function name>(c,a)<0)) 
TransiveChecker();
}

void test3_1(a,b){
NewTest();
if (<function name>(a,b) && <function name>(b,a)) /  if ((<function name>(a,b)>0)&&(<function name>(b,a)>0))
SymmetryChecker();
}

void test3_2(a,b){
NewTest();
if (<function name>(a,b) && <function name>(b,a)) /  if ((<function name>(a,b)<0)&&(<function name>(b,a)<0))
SymmetryChecker();
}

void test4(a){
NewTest();
If (<function name>(a, a))/if (<function name>(a, a)<0||<function name>(a, a)>0) 
ReflexivityChecker();
}

------------------------------------------------------------------------------------------------------

Please make the following code can be compiled:
Code requirements
1.All library functions appearing in the code are declared using functions and do not need to be implemented specifically. 
2.There is no need to include the main function. 
3.For the template type, please choose a type to replace the template type so that the program can compile successfully.
4.For the auto type, please infer a type that can replace auto so that the program can compile successfully.
5.Avoid using floating-point types when completing.

Output Format Specification(Only output code without explanation)
Desired format:
#include <bits/stdc++.h>
<Include necessary headers>
<Declaration of class or struct>
<Forward declarations of functions>
<the whole code can be compiled>