#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >>t ;
    while (t--) {
        long long x , y ;
        cin >> x >> y ;
        if (x == y) cout << 0 << endl ;
        else if (x < y) {
            
            // cout << (y / 10 + (y % 10 != 0)) << endl ;
            int ct = 0 ;
            while (x < y) {
                x += 10 ;
                ct ++ ;
            }

            cout << ct << endl ;
        
        }
        else {
            // cout << (x / 10 + (x % 10 != 0)) << endl ;

            int ct = 0 ;
            while (x > y) {
                x -= 10 ;
                ct++ ;
            }
            cout << ct << endl ;
        }
    }
    return 0 ;
}