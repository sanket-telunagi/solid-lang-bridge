#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int longestSubarrayWithSumK(vector<int> nums, long long k) {
    // Write your code here
    unordered_map<int,int> mp ;  // store the <sum , index>

    int res = 0 , 
        mxLen = 0 , r = 0 ,
        n = nums.size();
    long long sum = 0;

    for (r = 0; r < n ; r++)
    {
        sum += nums[r] ;

        if (sum == k) mxLen = max(mxLen, r+1) ;

        int rem = sum - k ;

        if (mp.find(rem) != mp.end()) {
            int len = r - mp[rem] ;
            mxLen = max(mxLen, len) ;
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = r ;
        }
    }
    
    return mxLen ;
    
}

int main()
{
    long long n , k;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << longestSubarrayWithSumK(nums, k) << endl ;
    return 0 ;
}