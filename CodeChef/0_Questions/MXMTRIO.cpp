#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int main()
{
    int t ;
    cin >> t ;
    while (t--)
    {
        int n ;
        cin >> n ;
        vector<long long> nums(n) ;
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i] ;
        }

        sort(nums.begin(), nums.end()) ; // sorting will get the min at first and max at last 

        if (nums[0] == nums[n - 1]) cout << 0 << endl ;

        else {
            long long ans = 0 ;
            long long t1 = (nums[n-1] - nums[0]) * nums[n-2] ; // the diffrence and the element should be maximum 
            long long t2 = (nums[n-2] - nums[0]) * nums[n-1] ;
            ans = max(t1, t2) ;
            cout << ans << endl ;
        }
        
    }

    return 0 ;
}