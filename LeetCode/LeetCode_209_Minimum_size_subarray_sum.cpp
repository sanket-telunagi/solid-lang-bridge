#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given an array of positive integers nums and a positive integer target, 
    return the minimal length of a subarray
    whose sum is greater than or equal to target.   
    If there is no such subarray, return 0 instead.
*/

int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0 , l = 0 , r = 0 , n = nums.size() , ct = INT_MAX;

    while (r < n) {
        sum += nums[r] ;
        if (sum < target) {
            r++ ;
        }
        else if (sum >= target) {
            while(sum >= target) {
                sum -= nums[l] ;
                l++ ;
            }
            r++ ;
            ct = min(ct, r - l + 1) ;
        } 
    
    }
    return ct == INT_MAX ? 0 : ct ;
}

int main()
{
    int n , t;
    cin >> n >> t ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << minSubArrayLen(t, nums) << endl ;
    
    return 0 ;
}