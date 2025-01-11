/*
    Lambda function : 

        - Lambda function is the anonymous function which can be assigned to any veriable
        - It is single liner

        Syntax : 

            [] (datatype veriable) { return the expression } ( call value )

            < dtype > < veriable_name > = [] ( < dtype veriable 1 > , < dtype veriable 2 > ) { return expression }

            call : < veriable name > ( atteributes )
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    
    int x = 2, y = 4 ;

    cout << [] (int a) { return a + 2 ;} (x) << endl ;

    auto sum = [] (int a, int b) { return a + b ; };

    cout << sum (x,y) << endl ;
    return 0 ;
}