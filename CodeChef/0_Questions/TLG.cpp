#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    int p1l = 0 , pl2 = 0 ;
    int total1 = 0 , total2 = 0 ;
    while (t--) {
        int x, y ;
        cin >> x >> y ;
        total1 += x ;
        total2 += y ;
        if (x >= y) {
            p1l = max(p1l, (total1 - total2)) ;
        } else pl2 = max(pl2, total2 - total1) ;
    }

    if (p1l > pl2) cout << 1 << " " << p1l << endl ;
    else cout << 2 << " " << pl2 << endl ;
    return 0 ;
}