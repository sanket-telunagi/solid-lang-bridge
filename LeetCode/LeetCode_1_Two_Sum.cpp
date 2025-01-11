/*
    Given an array of integers nums and an integer target, 
    return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.
    You can return the answer in any order.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> ans ;
//     int s = 0 , e = 0 ;
//     for (int i = 0; i < nums.size() - 1; i++)
//     {
//         s = i ;
//         for (int j = s + 1; j < nums.size(); j++)
//         {
//             e = j ;
//             if (nums[s] + nums[e] == target) {
//                 return {s,e} ;
//             }
//         }
        
//     }
// }

vector<int> twoSum(vector<int> & nums, int target) {
    unordered_map<int, int> mp ;
    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i] ;
        if (mp.find(complement) != mp.end()) {
            return {mp[complement],i} ;
        }
        mp[nums[i]] = i ;
    }
    return {} ;
}

int main()
{
    int n,k ; 
    cin >> n >> k ; 
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    
    for(int i : twoSum(nums,k)) {
        cout << i << " " ;
    }
    return 0 ;
}