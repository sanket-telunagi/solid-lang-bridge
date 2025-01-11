#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dp[1000][1000] ;

int knapSack(int W, int wt[], int val[], int n) 
{ 
    if (n == 0 || W == 0) return 0 ;
    if (dp[n-1][W] != -1) return dp[n-1][W] ;
    // not selected 
    int ans = knapSack(W, wt, val, n-1) ;

    if (wt[n-1] <= W) {
        ans = max(ans, knapSack(W - wt[n-1], wt, val, n-1) + val[n-1]) ;
    }

    return dp[n-1][W] = ans ;
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
    cout << knapSack(wt, weights, values, n) << endl ;

    return 0 ;
}