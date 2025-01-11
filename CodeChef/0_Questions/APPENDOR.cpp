#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    long long t ;
    cin >> t ;
    while(t--) {
        long long n, k;
        cin >> n >> k;
        long long or_val = 0 ;
        // take all or 
        for (long long i = 0 ; i < n ; i++) {
            long long x ;
            cin >> x ;
            or_val |= x ;
        }
        bool found = false ;
        for (long long i = 0; i <= k; i++) {
            if ((or_val | i) == k) {
                cout << i << endl ;
                found = true ;
                break ;
            }
        }

        if (!found) cout << -1 << endl ;
        
    }
    return 0 ;
}