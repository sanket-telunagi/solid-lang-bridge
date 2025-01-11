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
   
    int i = 0 , j = 1 ; 
    int n = nums.size() ;
    int ans = -1 ;
       for (int j = 0; j < n; j++)
        {
       
        

        if (abs(nums[i] - nums[j]) == 1) {
            
            
            int t1 = i + 2 , t2 = j + 2;
            while (nums[t1] == nums[i] && nums[t2] == nums[j] && t1 < n && t2 < n) {
                ans = max(ans, t2 - i + 1) ;
    
                t1 += 2 ;
                t2 += 2 ;
            }
            ans = max(ans, t2 - i + 1) ;
        }
        i++ ;
        j++ ;
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