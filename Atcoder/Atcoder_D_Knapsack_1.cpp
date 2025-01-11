#include<bits/stdc++.h>
#include <iostream>
using namespace std ;
const int N = 1e5 + 10 ;
long long dp[100][N] ;

long long knapsack1(int i , int mx_wt, vector<int> & val, vector<int> & wt) {
    if (i < 0) return 0 ; // no elements left to choose 
    if (mx_wt == 0) return 0 ; // capacity exhosted 

    // current number is not taken 
    long long ans = knapsack1(i - 1, mx_wt, val, wt) ;

    // current wt taken
    if (mx_wt - wt[i] >= 0)
    ans = max(ans, knapsack1(i - 1, mx_wt - wt[i], val, wt) + val[i]+ 0LL) ;
    return ans ;
}

long long knapsack1_dp(int i , int mx_wt, vector<int> & val, vector<int> & wt) {
    if (i < 0) return 0 ;
    if (mx_wt == 0) return 0 ;
    if (dp[i][mx_wt] != -1) return dp[i][mx_wt] ;
    // current number is not taken 
    long long ans = knapsack1_dp(i - 1, mx_wt, val, wt) ;

    // current wt taken
    if (mx_wt - wt[i] >= 0)
    ans = max(ans, knapsack1_dp(i - 1, mx_wt - wt[i], val, wt) + val[i]+ 0LL) ;
    return dp[i][mx_wt] = ans ;
}

int main()
{
    int n , mx_wt;
    cin >> n >> mx_wt ; 
    vector<int> val(n), wt(n) ;

    memset(dp, -1, sizeof(dp)) ;

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i] ;
    }
    cout << knapsack1_dp(n - 1, mx_wt, val, wt) << endl ;
    
    return 0 ;
}