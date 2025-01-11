#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Given a rod of length N inches and an array of prices, 
    price[]. price[i] denotes the value of a piece of length i. 
    Determine the maximum value obtainable by cutting up the rod and selling the pieces.
*/

int dp[100010] ;

int fun(int len, vector<int> & prices) {
    if (len == 0) return 0 ; // as if len is zero no rod to cut 
    int ans = 0 ;
    // cout << ans << " " << len << " " << endl ;
    for (int len_to_cut = 1; len_to_cut <= prices.size(); len_to_cut++)
    {
        if (len - len_to_cut >= 0) 
            ans = max(ans, fun(len - len_to_cut, prices) + prices[len_to_cut-1] );
    }

    return ans ;
    
}

int fun_dp(int len, vector<int> & prices) {
    if (len == 0) return 0 ; // len zro no rod to cut
    if (dp[len] != -1) return dp[len] ;
    int ans = 0 ;

    // we can cut minimum of len 1 unit rod 
    for (int len_to_cut = 1; len_to_cut <= prices.size(); len_to_cut++)
    {
        if (len - len_to_cut >= 0) 
            ans = max(ans, fun(len - len_to_cut, prices) + prices[len_to_cut-1] );
    }
    return dp[len] = ans ;
}

int cutRod(vector<int> & nums) {
    memset(dp, -1, sizeof(dp)) ;
    int len = nums.size() ;
    return fun_dp(len, nums) ;
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

    cout << cutRod(nums) << endl ;
    
    return 0 ;
}