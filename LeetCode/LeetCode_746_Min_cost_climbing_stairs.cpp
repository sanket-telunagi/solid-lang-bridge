#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int dp[100010] ;

int climb(vector<int> & cost, int i) {
    if (i >= cost.size()) return 0 ;
    if (dp[i] != -1) return dp[i] ;
    int mn_cost = INT_MAX ;

    // jumped one step 
   
    mn_cost = min(mn_cost, climb(cost, i + 1) + cost[i]) ;

   
    mn_cost = min(mn_cost, climb(cost, i + 2) + cost[i]) ;

    return dp[i] = mn_cost ;
}
int climb2 (int n, vector<int> cost) {
    if (n == 0 || n == 1) return cost[n] ;
    if (dp[n] != -1) return dp[n] ;

    return dp[n] = cost[n] + min(climb2(n-1, cost), climb2(n-2, cost)) ;
}

int minCostClimbingStairs(vector<int>& cost) {
    memset(dp, -1, sizeof(dp)) ;
    // return min(climb(cost,1),climb(cost, 0)) ;
    int n = cost.size() ;
    return min(climb2(n-1, cost),climb2(n - 2, cost)) ;

}

int main()
{
    int n ;
    cin >> n ;
    vector<int> cost(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i] ;
    }

    cout << minCostClimbingStairs(cost) ;
    return 0 ;
}