#include<bits/stdc++.h>
#include <iostream>

using namespace std ;


long long dp[105][100010] ;
long long knapsack_2(int i, long long val_left, vector<int> & wt, vector<int> & val) {
    if (val_left == 0) return 0 ;
    if (i < 0) return 1e15 ;
    
    long long ans = knapsack_2(i-1, val_left, wt, val) ;

    if (val_left - val[i] >= 0)
    ans = min(ans, knapsack_2(i-1, val_left - val[i], wt, val) + wt[i]) ;

    return ans ;
}

long long knapsack_2_dp(int i, long long val_left, vector<int> & wt, vector<int> & val) {
    if (val_left == 0) return 0 ;
    if (i < 0) return 1e15 ;
    if (dp[i][val_left] != -1) return dp[i][val_left] ;
    
    long long ans = knapsack_2_dp(i-1, val_left, wt, val) ;

    if (val_left - val[i] >= 0)
    ans = min(ans, knapsack_2_dp(i-1, val_left - val[i], wt, val) + wt[i]) ;

    return dp[i][val_left] = ans ;
}

int main()
{
    long long n , mx_wt;
    cin >> n >> mx_wt;
    vector<int>  val(n) , wt(n);
  
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i] ;
    }
    
    memset(dp, -1, sizeof(dp)) ;

    long long  mx_val = 1e5 ;
    for (long long i = mx_val ; i >= 0; i--)
    {
        if (knapsack_2_dp(n -1 , i, wt, val) <= mx_wt) {
            cout << i << endl ;
            break; 
        }
    }
    

    return 0 ;
}