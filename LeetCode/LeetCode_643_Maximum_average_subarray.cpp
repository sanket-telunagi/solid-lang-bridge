#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    You are given an integer array nums consisting of n elements, and an integer k.
    Find a contiguous subarray whose length is equal to k that 
    has the maximum average value and return this value. 
    Any answer with a calculation error less than 10e-5 will be accepted.
*/

double findMaxAverage(vector<int>& nums, int k) {
    double res = 0.0000000 ;

  

    // kadanes algo for maximum sum subarray 
    double curr_sum = 0 , mx = INT_MIN, mx_ct = INT_MIN, ct = 0 ;

    for (int it : nums) {
        if (curr_sum >= 0) {
            curr_sum += it ;
            ct++ ;
        }
     
        else  {
            curr_sum = it ;
            ct = 0 ;
        }
        mx = max(mx, curr_sum) ;
        mx_ct = max(mx_ct, ct) ;
    }

    res = mx / ct ;
    return res ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << setprecision(7) << findMaxAverage(nums, k) << endl ;
    return 0 ;
}