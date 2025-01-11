#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// void findPath (int vertex, int n , vector<int> & path) {
//     if (vertex >= n-1) {
//         paths.push_back(path) ;
//         return ;
//     }
//     for(auto child : g[vertex]) {
       
//         path.push_back(child) ;
//         findPath(child, n, path) ;
//         path.pop_back() ;
//     }
// }

void findPath(vector<vector<int>> & graph,vector<vector<int>> & ans, vector<int> & path , int vertex = 0 ) {
    if (vertex >= graph.size()-1) {
        ans.push_back(path) ;
        return ;
    }
    for(auto child : graph[vertex]) {
        path.push_back(child) ;
        findPath(graph, ans, path, child) ;
        path.pop_back() ;
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ans ;
    vector<int> path ;
    path.push_back(0) ;

    // as always start with '0' then push it already 
    // and then loop ans call recursion in children of node '0'
    
    findPath(graph,ans,path) ;
    return ans ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
   
   vector<vector<int>> graph(n) ;

    while(k--) {
        int v1, v2 ;
        cin >> v1 >> v2 ;
        // graph[v1][v2] = 1 ;
        graph[v1].push_back(v2) ;
    }

    // vector<int> path ;
    // path.push_back(0) ;
    // findPath(0, n , path) ;
    // for(auto it : paths){
    //     for(auto i : it) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }

    // for (auto & pr : g) {
    //     cout << pr.first << " : " ;
    //     for(auto i : pr.second) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }

    vector<vector<int>> ans = allPathsSourceTarget(graph) ;

    for(auto it : ans) {
        for(auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    return 0 ;
}

/*
    4 4
    0 1
    0 2
    1 3
    2 3
*/