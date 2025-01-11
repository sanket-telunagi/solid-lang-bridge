/*
    Q : Count the number of ways we can parenthesize the expression 
    so that the value of expression evaluates to true. 
    Let the input be in form of two arrays one contains the symbols (T and F) 
    in order and the other contains operators (&, | and ^}

    A : an expression can be evelauted in the ways by evaluating its subproblems 
        its subproblems can be evaluated in 4 ways 
        1. left subproblem evaluates true 
        2. left subproblem evaluates false 
        3. right subproblem evaluates true 
        4. right subproblem evaluates false 

*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int fun (string & s, int i , int j, bool isTrue) {
    if (i > j) return 0 ;

    if (i == j) {
        if (isTrue) return isTrue == true ;
        else return isTrue == false ;
    }

    // final answer
    int ans = 0 ;


    for (int k = i + 1; k < j-1; k += 2)
    {
        // temp answers 

        int LT = fun(s, i, k - 1, isTrue) ;
        int LF = fun(s, k + 1, j , isTrue ) ;
        int RT = fun(s, k+1, j, isTrue ) ;
        int RF = fun(s, k+1, j, isTrue) ;

        // final answer 
        if (s[k] == '^') {
            // number of ways '^' becomes true 
            if (isTrue) ans = ans + (LT * RF) + (LF * RT) ;

            // number of ways '^' becomes false 
            else ans = ans + (RT * LT) + (RF * LF) ;
        } 

        else if (s[k] == '&') {
            // number of ways '&' becomes true 
            if (isTrue) ans = ans + (LT * RT) ;
            
            // number of ways '&' becomes false 
            else ans = ans + (LF * RF) + (LF * RT) + (LT * RF) ;
        }

        else if (s[k] == '|') {
            // number of ways '|' becomes true 
            if (isTrue) ans = ans + (LT * RT) + (LT * RF) + (LF * RT) ;

            // number of ways '|' becomes false
            else ans = ans + (LF * RF) ;
        }

    }
    
    return ans ;

}

int solve (string & s) {
    int i = 0 , j = s.length() -1 ;
    return fun(s, i, j , false) ;
}

int main()
{
    string s ;
    cin >> s;
    cout << solve(s) << endl ;
    return 0 ;
}