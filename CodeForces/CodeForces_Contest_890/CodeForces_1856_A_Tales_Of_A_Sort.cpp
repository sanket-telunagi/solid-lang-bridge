#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    long long t ;
    cin >> t ;
    while (t--) {
        long long n ;
        cin >> n ;
        vector<long long> nums(n) ;
        for (long long i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        long long maximums[n] = {0} ;
        long long mx = INT_MIN ;
        long long res = 0 ;
        for (long long i = 0 ; i < n ; i++) {
            mx = max(mx, nums[i]) ;
            maximums[i] = mx ;
        }

        // for (int i : maximums) cout << i << " " ;
        // cout << endl ;

        for (long long i = n-1; i >= 0; i--)
        {
            if (nums[i] != maximums[i]) {
                res = maximums[i] ;
                break; 
            }
        }

        cout << res << endl ;
        

        
        
    }
    return 0 ;
}