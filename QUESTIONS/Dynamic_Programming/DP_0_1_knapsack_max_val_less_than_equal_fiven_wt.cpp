#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dp[1000][1000] ;

int knapSack_memoisation(int W, int wt[], int val[], int n) 
{ 
    if (n == 0 || W == 0) return 0 ;
    if (dp[n-1][W] != -1) return dp[n-1][W] ;
    // not selected 
    int ans = knapSack_memoisation(W, wt, val, n-1) ;

    if (wt[n-1] <= W) {
        ans = max(ans, knapSack_memoisation(W - wt[n-1], wt, val, n-1) + val[n-1]) ;
    }

    return dp[n-1][W] = ans ;
}

int knapSack_dp(int W, int * wt, int * val, int n) {
    int table [n+1][W+1] ;

    // fill the initial value in the table 
    // the initial value is nothing but the base condition in the recursive code

    for (int i = 0 ; i <= n ; i++) {
        
        table[i][0] = 0 ;
    }

    for (int i = 0 ; i <= W ; i++) {
        
        table[0][i] = 0 ;
    }

    // now start filling the table 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[j - 1] <= j) {
                table [i][j] = max(table[i-1][j], table[i-1][j - wt[i-1]] + val[i - 1]) ;
            } else {
                table[i][j] = table[i-1][j] ;
            }

            // cout << table[i][j] << " " ;
            
        }

        // cout << endl ;
    }

    return table[n][W] ;
    
}

int main()
{
    int n , wt;
    cin >> n >> wt;
    int weights[n], values[n] ;
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] ;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> values[i] ;
    }
    memset(dp, -1, sizeof(dp)) ;
    cout << knapSack_dp(wt, weights, values, n) << endl ;

    return 0 ;
}