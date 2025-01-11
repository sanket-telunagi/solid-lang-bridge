#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int fun(int idx, int diff,  unordered_map<int,int> dp[], vector<int> & nums) {
    if (idx == 0) return 0 ;
    if (dp[idx].count(diff)) return dp[idx][diff] ;
    // not choosing current index 
    int ans = 0 ;

    for (int i = idx - 1; i >= 0; i++)
    {
        ans = max(ans, fun(i , diff, dp, nums) + 1) ;
    }
    return dp[idx][diff] = ans ;
}

int longestArithSeqLength(vector<int>& nums) {
    int n = nums.size() ;
    if (n <= 2) return 0 ;
    int res = 0 ;
    unordered_map<int, int> dp([(n-1)]) ;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            res = max(res, fun(i, nums[j] - nums[i], dp, nums) + 2) ;
        }
        
    }
    return res ;
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
    
    return 0 ;
}