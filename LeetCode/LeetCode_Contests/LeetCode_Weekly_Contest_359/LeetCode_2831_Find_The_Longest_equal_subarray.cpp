#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int longestEqualSubarray(vector<int>& nums, int k) {
    /*
        Tract the freq of most freq element in the window  (maxf)
        if the (windowSize - maxf > k) reduce the size of the window 
        else continue increasing window 
    */

    int maxf = 0, left = 0 , right = 0 ;
    unordered_map<int, int> mp ;  // keep track of freq 
    int n = nums.size() ;
    for (right = 0 ; right < n ; right++) {
        maxf = max(maxf, ++mp[nums[right]]) ; // get the max freq each time 
        
        int windowSize = right - left + 1 ;
        if (windowSize - maxf > k) {
            // reducing the window because it will reduce the number of elements to be deleted 
            mp[nums[left]]-- ;
            left++ ;
        }
    }

    return maxf ;
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

    cout << longestEqualSubarray(nums, k) << endl ;

    
    return 0 ;
}