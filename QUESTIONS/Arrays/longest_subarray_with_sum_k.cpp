#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int longestSubarrayWithSumK(vector<int> nums, long long k) {
    // Write your code here
    int sum = 0 , 
        i = 0,
        l = 0,
        n = nums.size(),
        res = 0 ;

    for ( i = 0; i < n; i++)
    {
        sum += nums[i] ;
        while (sum > k) {
            sum -= nums [l] ;
            l++ ;
            // if (sum == k) res = max(res, i - l + 1) ;
        }
        if (sum == k) res = max(res, i - l + 1) ;
    }

    return res ;
    
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