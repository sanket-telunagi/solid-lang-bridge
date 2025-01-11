#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int peakIndexInMountainArray(vector<int>& nums) {
    int idx = 0 ,
        n = nums.size();
    // for (int i = 0; i < n-1; i++)
    // {
    //     if (nums[i+1] - nums[i] < 0) {
    //         idx = i ;
    //         break ;
    //     }
    // }

    int s = 0 , r = n - 1 , mid ;
    while (s < r) {
        mid = (s + r) / 2 ;
        if (nums[mid] < nums[mid + 1]) s = mid + 1 ;
        else r = mid ;
        idx = r ;
    }
    return idx ;
}

int main()
{
    int n;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << peakIndexInMountainArray(nums) << endl ;
    return 0 ;
}