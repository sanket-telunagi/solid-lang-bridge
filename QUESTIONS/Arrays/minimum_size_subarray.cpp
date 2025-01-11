/*
    Given an array of positive integers nums and a positive integer target, 
    return the minimal length of a subarray
    whose sum is greater than or equal to target. 
    If there is no such subarray, return 0 instead.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int minSubArrayLen(int target, vector<int>& nums) {
    int ans = INT_MAX ; // result 
    int l = 0  , n = nums.size(), sum = 0 ;

    for (int r = 0; r < n; r++)
    {
        sum += nums[r] ;  // add the sum (increase the window)
        while (sum >= target) { // once the target acheived start reducing to minimum size
            ans = min(ans, r - l + 1) ; // take the minimum size from the window
            sum -= nums[l] ;
            l++ ;
        }
    }

    if (ans == INT_MAX) return 0 ;
    return ans ;
}

int main()
{
    int n, k ;
    cin >> n >> k;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << minSubArrayLen(k, nums) ;
    
    return 0 ;
}