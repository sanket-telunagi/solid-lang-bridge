/*
    Given an array, rotate the array to the right by k steps, where k is non-negative.
*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    // reverse the array
    for (int i = 0; i < nums.size()/2; i++)
    {
        swap(nums[i] , nums[nums.size()-1-i]) ;
    }
    sort(nums.begin(),nums.end() - (nums.size() - k)) ;
    sort(nums.begin() + k, nums.end()) ;
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    rotate(nums,k) ;
    for (int & i : nums)
    {
        cout << i << " ";
    }
    return 0;
}