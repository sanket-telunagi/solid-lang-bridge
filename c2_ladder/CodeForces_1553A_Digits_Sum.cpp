#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t;
    cin >> t ;
    while (t--) {
        long long a ;
        cin >> a;
        // if (a < 9) cout << 0 << endl ;
        // else if ( a == 9) cout << 1 << endl ;
        // else cout << (a / 10) << endl ;

        /// the numbers are :
        // 9 19 29 39 49 ...
        long long res = 0  ;
        long long temp = 9 ;

    // correct but TLE
        // while (temp <= a) {
        //     res ++;
        //     temp += 10 ;
        // }
    
// the number will come exactly once in every 10 numbers 

    // handles if the number is 9, 19, 29 .....
        if (a % 10 == 9) cout << (a / 10 + 1) << endl ;
        else cout << (a / 10) << endl ;
    }
    return 0 ;
}