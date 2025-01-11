#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n ;
        cin >> n ;

        int res = 0 ;
        int ct = 1 ;
        int ans = 0 ;
        for (int i = 0; i < n; i++)
        {
            int a , b ;
            cin >> a >> b ;
            if (a <= 10) {
                if (b > res) {
                    res = max(res, b) ;
                    ans = ct ;
                }
            }
            ct++ ;
        }

        cout << ans << endl ;
        
    }
    return 0 ;
}