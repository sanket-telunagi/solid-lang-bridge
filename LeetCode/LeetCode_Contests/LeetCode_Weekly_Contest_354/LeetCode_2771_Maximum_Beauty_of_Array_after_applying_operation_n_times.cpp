#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int maximumBeauty(vector<int>& nums, int k) {
    int res = 0 ,
        n = nums.size();
    // for (int i = 0; i < n ; i++)
    // {
    //     int ct = 1 ;

    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (nums[j] == nums[i]) ct++ ;
    //         else {
    //             if (nums[i] >= nums[j] - k && nums[i] <= nums[j] + k) {
    //                 ct++ ;
    //             }
    //         }
    //     }
    //     res = max(res, ct) ;
    // }

    /*
        Look for the range [l, r] in sorted array 
        if (l - k) and (r + k) lies in it 
        suerly, evenry element between nums[l] and nums[r] can be made equal 
        ans : 
            r - l = 2*k
    */
    
    sort(nums.begin(), nums.end()) ;

    int l = 0 , r = 0 ;
    for (r = 0; r < n; r++)
    {
        while (nums[r] - nums[l] > 2*k) l++ ;
        res = max(res, r - l + 1) ;
    }
    

    return res ;
}


int main()
{
    int n , k;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << maximumBeauty(nums, k) ;
    return 0 ;
}