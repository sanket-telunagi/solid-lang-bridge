#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Q : Return the size of longest subarray of sum k 
*/

int longest_subarray_sum_k(vector<int> & nums, int k) {
    int res = INT_MIN ;

    int sum = 0 ;
    int i = 0 ;

    int n = nums.size() ;
    int r = 0 ;
    while (r < n)
    {
        // calculations 
        sum += nums[r] ;

        if (sum < k) {
            r++ ;
        }
        if (sum == k) {
            res = max(res, r - i + 1) ;
            r++ ;
        }
        else if ( sum > k) {
            while (sum > k) {
                sum -= nums[i++] ;
            
            }
            r++ ;
        }
    }
    return res ;
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

    cout << longest_subarray_sum_k(nums, k) ;

    
    return 0 ;
}