#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

unordered_map<string, int> mp ;


// TLE 
int solve (vector<vector<int>> & offers, int i , int prev_val = -1) {
    if (i >= offers.size()) return 0 ;
    int gold = 0 ;

    string key = to_string(offers[i][0]) + "&" + to_string(prev_val) ;

    if (mp.find(key) != mp.end()) return mp[key] ;
    cout << offers[i][0] << " " << offers[i][1] << " " << offers[i][2] << endl ;

    // dont choose current offer 
    gold = solve(offers, i+1, prev_val) ;

    // choose current offer 
    if (prev_val == -1 || offers[i][0] > prev_val) {
        gold = max(gold,  offers[i][2] + solve(offers, i+1, offers[i][1])) ;
    }

    return mp[key] = gold ;
}

bool cmp (vector<int> & a, vector<int> & b){ return a[1] < b[1] ;}



int maximizeTheProfit(int n, vector<vector<int>>& offers) {
//     sort(offers.begin(), offers.end(), cmp) ;
//     return solve(offers, 0) ;

    vector<int> dp(n + 1) ; // max value at every house 

    vector<vector<vector<int>>> mp (n + 1) ; // keep track of all the points ends at point 'e'

    for (auto & it : offers) {
        // making it one based indexing endpoints 
        mp[it[1] + 1].push_back({it[0]+1, it[1] + 1, it[2]}) ;
    }
    // starting with endpoints 
    for (int e = 1; e <= n; e++)
    {
        dp[e] = dp[e-1] ;
        // all the possible intervals 
        for (auto & it : mp[e]) {
            dp[e] = max(dp[e], dp[it[0]-1] + it[2]) ;
        }   
    }
    
    return dp[n] ;

}
int main()
{
    int n, of ;
    cin >> n >> of;
    vector<vector<int>> offers(of, vector<int> (3, 0)) ;
    for (int i = 0; i < of; i++)
    {
        cin >> offers[i][0] >> offers[i][1] >> offers[i][2] ;
    }

    cout << maximizeTheProfit(n, offers) << endl ;
    
    return 0 ;
}