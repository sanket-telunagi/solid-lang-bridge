#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , x ;
        cin >> n >> x ;
        int res = INT_MIN ;
        for (int i = 0; i < n; i++)
        {
            int s, r ;
            cin >> s >> r ;
            if ( s <= x) {
                res = max(res, r) ;
            }
        }
        cout << res << endl ;
    }
    return 0 ;
}