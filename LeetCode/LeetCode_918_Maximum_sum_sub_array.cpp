#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

//
int maxSubarraySumCircular(vector<int>& nums) {
    int cur_min = 0 , cur_max = 0 , total = 0 ;
    int min_min = nums[0] , max_max = nums[0] ;

    for (int i = 0; i < nums.size(); i++)
    {
        cur_min = min((cur_min + nums[i]), nums[i]) ;
        cur_max = max((cur_max + nums[i]), nums[i]) ;
        min_min = min(min_min, cur_min) ;
        max_max = max(max_max, cur_max) ;
        total += nums[i] ;
    }
    if (max_max > 0) return max(max_max, (total - min_min)) ;
    return max_max ;  
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

    cout << maxSubarraySumCircular(nums) << endl ;
    
    return 0 ;
}


// int maxSubarraySumCircular(vector<int>& nums) {
//     int n = nums.size() ;
//     int max_Sum = INT_MIN ;
//     int temp_max_sum = 0 ;

//     int arry_sum = 0 ;

//     int min_sum = INT_MAX ;
//     int temp_min_sum = 0 ;

//     for (int i = 0; i < n; i++)
//     {
//         arry_sum += nums[i] ;

//         temp_max_sum += nums[i] ;
//         max_Sum = max_Sum < temp_max_sum ? temp_max_sum : max_Sum ;
//         temp_max_sum = temp_max_sum < 0 ? 0 : temp_max_sum ;

//         temp_min_sum = nums[i] ;
//         min_sum = min_sum > temp_min_sum ? temp_min_sum : min_sum ;
//         temp_min_sum = temp_min_sum > 0 ? 0 : temp_min_sum ;
//     }
    
//     if (arry_sum == min_sum) return max_Sum ;

//     return max(max_Sum, (arry_sum - min_sum)) ;
// }