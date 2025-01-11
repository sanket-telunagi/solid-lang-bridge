#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long dp[210][100010] ;

int fun(int idx, int sum_remain, vector<int> & nums) {
    if (sum_remain == 0) return true ;
    if (idx < 0) return false ;
    // cout << idx << " " << nums[idx] << " " << sum_remain << endl ;
    // not considered current index 
    int ans = fun(idx - 1, sum_remain, nums) ;

    // consider current element 
    if (sum_remain -  nums[idx] >= 0)
        ans |= fun(idx - 1, sum_remain - nums[idx], nums) ;

    return ans ;
}

bool fun_dp(int idx, int sum_remain, vector<int> & nums) {

    if (sum_remain == 0) return true ;
    if (idx < 0) return false ;
    if (dp[idx][sum_remain] != -1) return dp[idx][sum_remain] ;
    // cout << idx << " " << nums[idx] << " " << sum_remain << " " << dp[idx][sum_remain] << endl ;
    // not considered current index 
    bool ans = fun_dp(idx - 1, sum_remain, nums) ;

    // consider current element 
    if (sum_remain -  nums[idx] >= 0)
        ans |= fun_dp(idx - 1, sum_remain - nums[idx], nums) ;

    return dp[idx][sum_remain] = ans ;
}

bool canPartition(vector<int>& nums) {

    // therequired sum will be half of the given sum 
    for (int i = 0; i < 210; i++)
    {
        for (int j = 0; j < 210; j++)
        {
            dp[i][j] = -1 ;
        }
        
    }
    
    int sum = 0 ;
    for (int i = 0 ; i < nums.size(); i++) {
        sum += nums[i] ;
    }
    if (sum % 2 != 0) return false ;

    sum = sum / 2;
    return fun_dp(nums.size()-1, sum, nums) ;
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
    
    cout << canPartition(nums) << endl ;

    return 0 ;
}