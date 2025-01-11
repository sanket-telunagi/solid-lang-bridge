/*
    Given an undirected tree consisting of n vertices numbered from 0 to n-1, 
    which has some apples in their vertices. 
    You spend 1 second to walk over one edge of the tree. 
    Return the minimum time in seconds you have to spend to collect all apples in the tree, 
    starting at vertex 0 and coming back to this vertex.

    The edges of the undirected tree are given in the array edges,
    where edges[i] = [ai, bi] means that exists an edge connecting the vertices ai and bi. 
    Additionally, there is a boolean array hasApple, 
    where hasApple[i] = true means that vertex i has an apple; 
    otherwise, it does not have any apple.
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

int DFS(unordered_map<int,vector<int>> & graph, vector<bool> & hasApple,int root = 0, int par = -1) {
    int total_time = 0 , sub_tree_time = 0 ;
    for( auto & child : graph[root]) {
        if (child == par) continue ;
        sub_tree_time = DFS(graph, hasApple, child, root) ;

        if (sub_tree_time || hasApple[child]) {
            total_time += (sub_tree_time + 2) ;
        }
    }
    return total_time;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {

    unordered_map<int,vector<int>> list ;
    for (auto & it : edges) {
        list[it[0]].push_back(it[1]) ;
        list[it[1]].push_back(it[0]) ;
    }
    // for (auto & pr :list) {
    //     cout << pr.first << " : " ;
    //     for (int & i : pr.second) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }
    return DFS(list, hasApple) ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<vector<int>> edges(n-1, vector<int> (2,0)) ;
    for (int i = 0 ; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1] ;
    }
    vector<bool> hasApples(n) ;
    for (int i = 0; i < n; i++)
    {   
        bool x ;
        cin >> x ;
        hasApples[i] = x ;
    }
    
    // for(auto it : edges) {
    //     cout << it[0] << " " << it[1] << endl  ;
    // }
    cout << endl ;
    cout << minTime(n,edges, hasApples) ;
    return 0 ;
}