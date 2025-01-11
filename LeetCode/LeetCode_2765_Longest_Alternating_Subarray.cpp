#include<bits/stdc++.h>
#include <iostream>
using namespace std ;


int alternatingSubarray(vector<int>& nums) {
    // consider the problem as sliding window problem 

    // slide the window by two
    /*
        Take one pair 
        if the difference is 1 
            then check for the same elements in the rest of the array 
        else take teh imidiate next pair 
    */

    // int i = 0 , j = 1 ; 
    // int n = nums.size() ;
    // long long ans = -1 ;
    // // while (j < n && j < 100) {
    // for (int j = 1; j < n; j++)
    // {
       
    //     int ptr1 = i , ptr2 = j ;

    //     if (abs(nums[ptr1] - nums[ptr2]) == 1) {
    //         long long t1 = ptr1 , t2 = ptr2 ;
    //         long long l = i , r = t2 ;
    //         t1 += 2;
    //         t2 += 2 ;
    //         ans = max(ans , r - l + 1) ;
    //         r += 2;
            
    //       while (nums[t1] == nums[i] && nums[t2] == nums[j] ) {
    //             ans = max(ans, r - l + 1) ;
    //             r += 2 ;
    //             t1 += 2 ;
    //             t2 += 2 ;
    //         }
    //     }
    //     i++ ;
      
    // } 

    int ans = -1 ;
    int n = nums.size() ;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; (j < n) && nums[j] == nums[i] + (j - i) % 2; j++)
        {
            ans = max(ans, j - i + 1) ;
        }
        
    }
    
    return ans ;
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
    cout << alternatingSubarray(nums) << endl ;
    return 0 ;
}