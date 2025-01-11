#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*

    Q : You are given a binary array nums.
        A subarray of an array is good if it contains exactly one element with the value 1.
        Return an integer denoting the number of ways to split the array nums into good subarrays. 
        As the number may be too large, return it modulo 10^9 + 7.
        A subarray is a contiguous non-empty sequence of elements within an arr
*/

int numberOfGoodSubarraySplits(vector<int>& nums) {
    int ct = 0 ;
    int M = 1e9 + 7 ;

    int count = 0 ;
    // for (int it : nums) {
    //     if (it == 1) count++ ;
    // }

    // if (count == 1) return 1 ;

    // int l = 0, r = 0, sum = 0, n = nums.size() ;

    // while(r <= n) {
    //     sum += nums[r] ;
    //     if (sum == 1) {
    //         ct++ ;

    //         for (int i = l; i <= r; i++)
    //         {
    //             std :: cout << nums[i] << " " ;
    //         }
    //         std :: cout << endl ;
            
    //     }
    //     else if (sum > 1) {
    //         while (sum > 1) {
    //             sum -= nums[l] ;
    //             l++ ;
    //         }
    //     }
    //     r++ ;
    // }

    // start from begining 

    int r = 0, l = -1 , n = nums.size() ;

    while (r < n) {

        if (nums[r] == 1) {
            
            if (ct == 0) {
                ct = 1 ;
            } else {
                ct *=  (r - l) ;
                ct = ct % M ;
            }
            
            l = r ;
        }

        r++ ;
    }

    return ct ;
}

int main()
{
    int n ;
    std :: cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> nums[i] ;
    }
    cout << numberOfGoodSubarraySplits(nums) << endl ;
    return 0 ;
}