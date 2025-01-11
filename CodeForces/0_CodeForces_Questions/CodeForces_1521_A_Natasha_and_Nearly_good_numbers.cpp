#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        long long x, y ; 
        cin >> x >> y ;
        // break problem into 
        // A + A.B = A.(B+1)
        if (y == 1) cout << "NO\n" ;
        else cout << "YES\n" << x << " " << x * y << " " << x * (y+1) << endl ;
    }
    return 0 ;
}