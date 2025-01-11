#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given a binary array nums, you should delete one element from it.
    Return the size of the longest non-empty subarray 
    containing only 1's in the resulting array. 
    Return 0 if there is no such subarray.    
*/

int longestSubarray(vector<int>& nums) {
    int res = 0 , n = nums.size();
    int l = 0 , r = 0 , ZC = 0 ;

    while (r < n) {
        if (nums[r] == 0) ZC++ ;

        if (ZC <= 1) {
            res = max(res,  r - l + 1) ;
        }
        else if (ZC > 1) {
            while (ZC > 1) {
                if (nums[l] == 0) {
                    ZC-- ;
                }
                l++ ;
            }
        }
        // cout << l << " " << r << " " << ZC << endl ;

        r++ ;
    }

    return res-1 ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << longestSubarray(nums) << endl ;
    
    return 0 ;
}