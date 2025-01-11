/*
    Given an numsay of integers nums, calculate the pivot index of this numsay.

    The pivot index is the index where the sum of all the numbers strictly to the left of the index 
    is equal to the sum of all the numbers strictly to the index's right.

    If the index is on the left edge of the numsay, then the left sum is 0 because there are no elements to the left. 
    This also applies to the right edge of the numsay.

    Return the leftmost pivot index. If no such index exists, return -1.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

int findPivote(vector<int> & nums) {
    vector<int> preSum ;
    preSum.push_back(nums[0]) ;
    for (int i = 1; i < nums.size(); i++){
        preSum.push_back(preSum[i-1] + nums[i]) ;
    }
    
    int leftSum = 0 , rightSum = 0 ; 
    for (int i = 0; i < nums.size(); i++)
    {
        i == 0 ? leftSum = 0 : leftSum = preSum[i-1] ;
        i == (nums.size() - 1) ? rightSum = 0 : rightSum = preSum[nums.size() - 1] - preSum[i] ;
        if (leftSum == rightSum) return i ;
    }
    return -1 ;
}

int main() {
    
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i =0 ; i < n ; i++) {
        cin >> nums[i] ;
    }

    cout << findPivote(nums) << endl;

    return 0 ;
}