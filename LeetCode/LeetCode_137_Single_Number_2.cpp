#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given an integer array nums where every element appears three times except for one, 
    which appears exactly once. Find the single element and return it.
    You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

int singleNumber(vector<int>& nums) {
    // solving by bit masking 
    // start with last bit of each number 
    // as the numbers are repeating 3 times any extra bit will be the bit of uique number 
    // hence we will flip the bit of that place in the answer variable 
    int res = 0 ;
    int n = nums.size() ;
    for (int i = 0; i < 32; i++)
    {
        int sum = 0 ;
        for (int j = 0; j < n; j++)
        {
            if ((nums[j] >> i) & 1) {
                sum++ ;
            }
        }
        sum %= 3 ;

        if (sum != 0) {
            res |= sum << i ;

        }
    }
    return res ;

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
    cout << singleNumber(nums) << endl ;
    return 0 ;
}