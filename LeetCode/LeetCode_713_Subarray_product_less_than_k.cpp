#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int j = 0 , i = 0 , n = nums.size(), ct = 0 ;
    long long prod = 1 ;

    while (j < n) {
        prod *= nums[j] ;
        if (nums[j] < k) {
            ct++ ;
            
        }
        if (prod < k) {
            cout << prod << endl ;
            ct++ ;
            
        } else if (prod >= k) {
            while (prod >= k) {
                prod /= nums[i] ;
                i++ ;
            }
            
        }
        j++ ;
    }
}

int main()
{
    int n , k;
    cin >> n >> k;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    cout << numSubarrayProductLessThanK(nums, k) << endl ;
    
    return 0 ;
}