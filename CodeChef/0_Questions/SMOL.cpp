#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t;
    while (t--) {
        int n , k ;
        cin >> n >> k ;
        int res = n ;
        int max_exe = 10000 ;
        while (res >= 0 && max_exe--) {
            if ( res - k >= 0)
                res = res - k ;
        }
        cout << res << endl ;
    }
    return 0 ;
}