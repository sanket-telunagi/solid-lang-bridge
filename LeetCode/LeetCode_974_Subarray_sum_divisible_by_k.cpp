/*
    Given an integer array nums and an 
    integer k, return the number of 
    non-empty subarrays that have a sum
    divisible by k.
    A subarray is a contiguous part of an 
    array.
*/
#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int subarraysDivByK(vector<int>& nums, int k) {
    if (nums.size() == 1) {
        if (0 == nums[0]) return 0 ;
        else if (nums[0] % k == 0) return 1 ;
        else {
            return 0 ;
        }
    }
    int ct = 0 ;
    int sum = 0 ;
    int rem = 0 ;
    unordered_map<int,int> mp ;
    mp[0] = 1 ;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] ;
        rem = sum % k ;
        if (rem < 0) rem += k;
        if (mp.find(rem) != mp.end()) {
            ct += mp[rem] ;
            mp[rem] = mp[rem] + 1 ;
        }else {
            mp[rem] = 1 ;
        }
    }
    return ct ;
}

int main()
{
    int n , k;
    cin >> n >> k;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << subarraysDivByK(nums, k) << endl ;
    
    return 0 ;
}

/*
    --- Gives TLE 

    int subarraysDivByK(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            if (0 == nums[0]) return 0 ;
            else if (nums[0] % k == 0) return 1 ;
            else {
                return 0 ;
            }
        }
        int ct = 0 ;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = nums[i] ;
            if (sum % k == 0) ct++ ;
            for (int j = i+1; j < nums.size(); j++)
            {
                sum += nums[j] ;
                if (sum % k == 0) ct++ ;
            }
            
        }
        return ct ;
    }
*/