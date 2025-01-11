#include <bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    Q : Find the count of longest increasing subsequence 
*/

int longest_increasing_subsequence(int idx,  vector<int> & nums, vector<int> & dp) {
    
    if (dp[idx] != 0) return dp[idx] ;



    int ct = 1 ;

    for (int j = 0; j < idx; j++)
    {
        if (nums[j] < nums[idx]) {
            ct = max(ct, longest_increasing_subsequence(j, nums, dp) + 1) ;
        }
    }

    return dp[idx] = ct ;

}

int main() {
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }

    vector<int> dp(n, 0) ;
    
    int ans = 0 ;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, longest_increasing_subsequence(i, nums, dp)) ;
    }
    
    cout << ans << endl ;

    
    return 0 ;
}