#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int bestTimeToBuyAndSellStock(vector<int> & nums) {
    // int n = nums.size() ;
    // int profit = 0 ;
    // for (int i = 0; i < n; i++)
    // {
    //     int buy = nums[i] ;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         profit = max(profit , (nums[j] - nums[i])) ;
    //     }
        
    // }

    // using two pointers 
    int l = 0 , r = 0 ; 
    int n = nums.size(), 
        profit = INT_MIN ; 

    // for (r = 0; r < n; r++)
    // {
    //     if (nums[r] < nums[l]) {
    //         l = r ;
    //     }
    //     profit = max(profit, nums[r] - nums[l]) ;
    // }
    int minPrice = INT_MAX ;

    for (int it : nums) {
        minPrice = min(it, minPrice) ;
        profit = max(profit, it - minPrice) ;
    }
    

    return profit ;
    
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int  i = 0; i < n; i++)
    {
        /* code */
        cin >> nums[i] ;
    }
    cout << bestTimeToBuyAndSellStock(nums) << endl ;
    return 0 ;
}