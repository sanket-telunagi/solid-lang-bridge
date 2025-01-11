#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int max_subarray_sum (vector<int> & nums, int k) {
    int mx = INT_MIN, n = nums.size(), i = 0 , j = 0, sum = nums[j] ;

    while (j != n)
    {
        // creating window
        while ((j - i + 1) < k)
        {
            sum += nums[++j] ;
        }

        // maintain window and do the calculations
        // cout << i << " " << j << " " << sum << endl ;
        // cout << sum << " " ;
        mx = max(mx, sum) ;
        // j++ ;
        sum = sum + nums[++j] - nums[i++] ;
        // i++ ;
        // cout <<  mx << " " ;
    }
    cout << endl ;

    return mx ;
}

// double findMaxAverage(vector<int>& nums, int k) {
//     double ans ;
//     int  n = nums.size(), i = 0 , j = 0 ;

//     double sum = double(nums[j]), mx = 1e-5;

//     while (j != n)
//     {
//         // creating window
//         while ((j - i + 1) < k)
//         {
//             sum += double(nums[++j]) ;
//         }

//         // maintain window and do the calculations
//         // cout << i << " " << j << " " << sum << endl ;
//         // cout << sum << " " ;
//         mx = max(mx, sum) ;
//         // j++ ;
//         sum = sum + double(nums[++j] - nums[i++]) ;
//         // i++ ;
//         // cout <<  mx << " " ;
//     }
//     ans = (sum / k) ;
//     return ans ;
// }

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << max_subarray_sum(nums, k) ;
    // cout << findMaxAverage(nums, k) ;
    return 0 ;
}