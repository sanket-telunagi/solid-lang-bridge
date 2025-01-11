#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*

    Q : 
        Given an array of integers nums and an integer k, 
        return the total number of subarrays whose sum equals to k.
        A subarray is a contiguous non-empty sequence of elements within an array.
*/

int subarraySum(vector<int> & nums, int k) {
    int ct = 0, sum = 0 ;
    unordered_map<int, int> mp ;
    mp[0] = 1 ; // as the current subarray wont contain any count for 0
    for (int it : nums) {
        sum += it ;
        int diff = sum - k ;
        if (mp.find(diff) != mp.end()) {
            ct += mp[diff] ;
        }
        mp[sum]++;
    }
    return ct ;
}

int main()
{
    int n , k;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << subarraySum(nums, k) << endl ;
    
    return 0 ;
}