/*
    It is a sweltering summer day, and a boy wants to buy some ice cream bars.
    At the store, there are n ice cream bars. You are given an array costs of length n, 
    where costs[i] is the price of the ith ice cream bar in coins. 
    The boy initially has coins coins to spend, 
    and he wants to buy as many ice cream bars as possible. 
    Return the maximum number of ice cream bars the boy can buy with coins coins.
    Note: The boy can buy the ice cream bars in any order.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// int maxIceCreamHelper(vector<int>& costs, vector<int> & dp, int coins, int index = 0) {
//     int ct = 0 ;
//     if (coins == 0 || index >= costs.size()) {
//         return 0 ;
//     }
//     if (dp[ct] != -1) return dp[ct] ;
//     ct = max(ct,maxIceCreamHelper(costs, dp, coins, index + 1)) ;
//     if (costs[index] <= coins) {
//         ct = max(ct,maxIceCreamHelper(costs, dp,coins - costs[index] , index+1)+1) ;
//     }
//     return dp[ct] = ct ;
// }

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(),costs.end())  ;
    int ct = 0;
    for (int i = 0; i < costs.size(); i++)
    {
        if(coins == 0) break ;
        if(costs[i] <= coins) {
            coins -= costs[i] ;
            ct++ ;
        }
    }
    return ct ;
}

int main()
{
    int n , coins ;
    cin >> n >> coins ;
    vector<int> costs(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> costs[i] ;
    }
    vector<int> dp(n,-1) ;

    cout << maxIceCream(costs, coins) ;
    
    return 0 ;
}