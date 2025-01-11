#include<bits/stdc++.h>
#include <iostream>
// # define "long long" int
using namespace std ;

int main()
{
    long long t ;
    cin >> t ;
    while(t--) {
        long long n ;
        cin >> n ;
        vector<long long> nums (n) ;
        for (long long i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        long long sum = accumulate(nums.begin(), nums.end(), 0) ;
        if (sum % 2 == 0) cout << "YES\n" ;
        else cout << "NO\n" ;
        
    }
    return 0 ;
}