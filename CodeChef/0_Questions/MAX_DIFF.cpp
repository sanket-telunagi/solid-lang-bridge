#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n , s ;
        cin >> n >> s ;
        int res = 0 ;
        // TLE
        // for (int i = 0; i <= n; i++)
        // {
        //     for (int j = 0; j <= n; j++)
        //     {
        //         if (i + j == s) {
        //             int diff = abs(i-j) ;
        //             res = max(res, diff) ;
        //         }
        //     }
            
        // }

        // for (int i = 0; i <= n; i++)
        // {
        //     if (i + (s - i) == s)
        //     {int diff = abs(i -  (s - i)) ;
        //     res = max(res, diff) ;}

        // }

        if ( n >= s) res = s ;
        else res = n - (s - n) ;
        
        cout << res << endl ;
    }
    
    return 0 ;
}