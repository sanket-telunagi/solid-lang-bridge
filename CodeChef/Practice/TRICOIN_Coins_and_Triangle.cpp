/*
    The sum of coins is nothing but sum of natural numbers of height h 
    just make an quadratic equation
    n^2 + n - 2*x = 0 
    where : 
        n = heght
        x = sum of coins (input)
    
    cout << integer of x
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;
int main() {
    int t ;
    cin >> t ;
    while(t--) {
        int x ;
        cin >> x ;
        int n = (-1 + sqrt(1 + 8*x)) / 2 ;
        cout << n << endl ;
    }
    return 0 ;
}