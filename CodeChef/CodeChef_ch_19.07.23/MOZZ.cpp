#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int x, y , r ;
        cin >> x >> y >> r ;
        float total = x + ((int)(r / 30)) ;
        // cout << total << endl ;
        int ct = 0 ;
        int sticks = 0 ;
        int ans = ceil(total / y) ;
        cout << ans << endl ;   
    }
    
    return 0 ;
}