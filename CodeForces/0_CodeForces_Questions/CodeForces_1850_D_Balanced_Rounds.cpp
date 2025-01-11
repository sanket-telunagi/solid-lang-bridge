#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--) {
        int n , k ;
        cin >> n >> k;
        vector<int> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        sort(nums.begin(), nums.end()) ;

        int ct = 1, res = 1 ;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i-1] > k) ct = 1 ;
            else ct ++ ;
            res = max(res, ct) ;
        }
        
        cout << n - res << endl ;
    }
    return 0 ;
}