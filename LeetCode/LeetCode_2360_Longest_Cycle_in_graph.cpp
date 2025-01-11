#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool dfs(int node, int start, vector<int> & path, vector<bool> & visited, unordered_map<int, vector<int>> & g) {
    visited[node] = true ;
    bool isLoop = false ;
    for (auto & child : g[node]) {
        if (visited[child] && child == start) return true ;
        isLoop |= dfs(child,start,  path, visited, g) ;
        if (isLoop) path.push_back(child) ;
    }
    
    return isLoop ;
}

int longestCycle(vector<int>& edges) {
    unordered_map<int, vector<int>> adj ;
    for (int i = 0; i < edges.size(); i++)
    {
        if (edges[i] == -1) continue ;
        adj[i].push_back(edges[i]) ;
    }
    // for (auto & pr : adj) {
    //     cout << pr.first << " : " ;
    //     for (auto & it : pr.second) {
    //         cout << it << " " ;
    //     }
    //     cout << endl ;
    // }
    int res = -1 ;
    for (int i = 0 ; i < edges.size() ; i++) {
       
        vector<int> path ;
        vector<bool> visited(edges.size() + 1) ;
        int node = i ;
        (dfs(node, node, path, visited, adj)) ;
        int n = path.size() ;
        res = max(res, n) ;
        for (auto it : path) cout << it << " " ;
        cout << endl ;
    }

    return res ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int> nums(n) ;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i] ;
    }
    cout << longestCycle(nums) << endl ;
    return 0 ;
}