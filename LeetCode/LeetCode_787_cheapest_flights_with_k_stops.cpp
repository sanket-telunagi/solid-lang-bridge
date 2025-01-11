#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

long long DFS(vector<vector<pair<int,int>>> & g, int src, int dst, int k , vector<vector<int>> & dp) {
    if (src == dst) return 0 ;
    if (k < 0) return INT_MAX ;
    if (dp[src][k] != -1) return dp[src][k] ;
    long long ans = INT_MAX ;
    for (int i = 0 ; i < g[src].size() ; i++) {
        ans = min(ans, g[src][i].second + DFS(g,g[src][i].first, dst, k - 1, dp)) ;
    }
    return dp[src][k] = ans ;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
        vector<bool> visited(n,false);
        for(int i=0;i<flights.size();++i){
            v[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

    // int i = 0 ;
    // for (auto & it : v) {
    //     i++ ;
    //     cout << i << " : " ;
    //     for (auto & j : it) {
    //         cout << j.first << " " << j.second << endl ;
    //     }
    // }

    // dp
    vector<vector<int>> dp (n , vector<int>(k+1, -1)) ;

    long long ans = DFS(v, src, dst, k , dp) ;
    if (ans >= INT_MAX) return -1 ;
    return ans ;
}


// long long helper(vector<vector<pair<int,int>>> &v,int src,int dst,int k,vector<vector<int>> &dp){
// if(src==dst){
//     return 0;
// }
// if(k<0){
//     return INT_MAX;
// }
// if(dp[src][k]!=-1){
//     return dp[src][k];
// }
// long long ans=INT_MAX;
// for(int i=0;i<v[src].size();++i){
//         ans=min(ans,v[src][i].second+helper(v,v[src][i].first,dst,k-1,dp));
// }
// return dp[src][k]=ans;
// }
// int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst, int k) {
//     vector<vector<pair<int,int>>> v(n,vector<pair<int,int>>());
//     vector<bool> visited(n,false);
//     for(int i=0;i<flight.size();++i){
//         v[flight[i][0]].push_back({flight[i][1],flight[i][2]});
//     }
//     vector<vector<int>> dp(n,vector<int>(k+1,-1));
//     long long ans=helper(v,src,dst,k,dp);
//     if(ans>=INT_MAX){
//         return -1;
//     }
//     return ans;
// }


int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> flights(n, vector<int>(3,0)) ;
    for (int i = 0; i < n; i++)
    {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2] ;
    }
    // int i = 0 ;
    // for( auto & it : flights) {
    //     i++ ;
    //     cout << i << " : " ;
    //     for (auto & j : it) {
    //         cout << j << " " ;
    //     }
    //     cout << endl ;
    // }
    int src, dest, k ;
    cin >> src >> dest >> k ;
    cout << findCheapestPrice(n, flights, src, dest, k) << endl ;
    return 0 ;
}