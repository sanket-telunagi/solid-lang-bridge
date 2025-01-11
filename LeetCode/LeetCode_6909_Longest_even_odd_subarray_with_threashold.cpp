#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void printV(vector<int> & nums, int l, int r) {
    for (int i = l; i <= r; i++)
    {
        cout << nums[i] << " " ;
    }
    cout << endl ;
    
}

int longestAlternatingSubarray(vector<int>& nums, int threshold) {
    int l = 0 , r = l + 1 , res = 0 , i = 0;

    while (l <= r)
    {
        if (nums[l] % 2 == 0) {
            if (nums[i] <= threshold) {
                if (nums[i] % 2 != nums[i+1] % 2 && l + 1 < r) {
                    r++ ;
                }
                res = max(res, l - r + 1) ;
                r++ ;
            }
            printV(nums,l, r) ;
            i++ ;
            r++ ;
        }
        l++ ;
   
        i++ ;
    }
    return res ;
}

int main()
{
    int n, t ;
    cin >> n >> t ;
    vector<int> nums(n) ;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;

    }
    cout << longestAlternatingSubarray(nums, t) << endl ;

    return 0 ;
}