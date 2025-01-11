#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Start at lat index and find the cost to reach at first index 
*/
const int N = 1e5 + 10 ;
int dp[N] ;

int minCost(vector<int> & nums, int i) {
    if (i <= 0 ) return 0 ;
    int cost = INT_MAX ;

    cost = min(cost, minCost(nums, i-1) + abs(nums[i] - nums[i-1])) ;

    if (i > 2) {
        cost =  min(cost, minCost(nums, i-2) + abs(nums[i] - nums[i-2])) ;
    }
  
    return cost ;
}

// state of dp 1
long long minCost_dp(int n , vector<int> & nums) {
    if (n == 0) return 0 ;
    if (dp[n] != -1) return dp[n] ;

    long long cost = INT64_MAX ;
    // jump of 1
    cost = min(cost, minCost_dp(n -1, nums) + abs(nums[n] - nums[n-1])) ;

    if (n > 1) {
        cost =  min(cost, minCost_dp(n -2,nums) + abs(nums[n] - nums[n-2])) ;
    }
    return dp[n] = cost ;
}

int main()
{
    int n ;
    cin >> n ;
    int N = 1e5 + 10 ;
    vector<int> nums(n, 0) ; 

    memset(dp, -1, sizeof(dp)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    // cout << minCost(nums, n-1) ;
    cout << minCost_dp(n-1, nums) << endl ;
    
    return 0 ;
}