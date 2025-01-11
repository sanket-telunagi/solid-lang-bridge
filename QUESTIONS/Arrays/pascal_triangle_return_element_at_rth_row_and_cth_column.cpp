#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int getElement(int r, int c) {

    /*  
        PT : Pascal Triangle
        C : Combination
        This has formula : 

            PT (r,c) = (r - 1) C (c - 1)
            
            The following code is for calculating : nCr

    

    */
    long long res = 1 ;
    for (int i = 0; i < c ; i++) {
        res = res * (r - i) ;
        res = res / (i + 1) ;
    }

    return res ;
}

int main()
{
    int r, c ;
    cin >> r >> c ;
    cout << getElement(r-1, c-1) << endl ;
    return 0 ;
}