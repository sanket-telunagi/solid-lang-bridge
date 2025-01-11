#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Kadens Algorithm - 
        - Take a variable currsum which takes the current sum 
        - maxsum variable denotes the maximum sum till current element 
        - complexity time - O(n)
*/

int max_sum_subarray(vector<int> & nums) {
    int n = nums.size() ;
    int curr_sum = 0 , max_sum = INT_MIN ;
    for (int i = 0; i < n; i++)
    {
        if (curr_sum >= 0) curr_sum += nums[i] ;
        else curr_sum = nums[i] ;
        max_sum = max(max_sum, curr_sum) ;

    // also works
        // curr_sum = max(curr_sum + nums[i], nums[i]) ;
        // max_sum = max(max_sum, curr_sum) ;
    }
    return max_sum ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums (n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << max_sum_subarray(nums) ;
    return 0 ;
}