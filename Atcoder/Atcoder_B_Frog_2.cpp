#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int minCost_f2 (int i, int k, vector<int> & h) {
    if (i == 0 ) return 0 ;
    int cost = INT_MAX ;
    
    for (int j = 1 ; j <= k; j++) {
        if (i - j >= 0) {
           
            cost = min(cost, minCost_f2(i - j, k, h) + abs(h[i] - h[i - j]) ) ;
        }
    }
    return cost ;
}

int minCost_f2_dp(int i, int k, vector<int> & h, int * dp) {
    if (i == 0 ) return 0 ;
    if (dp[i] != -1) return dp[i] ;
    int cost = INT_MAX ;
    
    for (int j = 1 ; j <= k; j++) {
        if (i - j >= 0) {
           
            cost = min(cost, minCost_f2_dp(i - j, k, h, dp) + abs(h[i] - h[i - j]) ) ;
        }
    }
    return dp[i] = cost ;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n) ;
    const int N = 1e5 + 10 ;
    int dp[N] ;
    memset(dp, -1 , sizeof(dp)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> h[i] ;
    }

    cout << minCost_f2_dp(n - 1, k, h, dp) << endl ;
    
    return 0 ;
}