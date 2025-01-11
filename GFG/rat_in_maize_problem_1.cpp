#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

/*
    take input as a graph and apply dfs on it 
*/

vector<bool> visited ;

void findPath(int vertex ,int parent ,  unordered_map<int, unordered_set<int>> & graph, vector<vector<int>> & ans, vector<int> & path){
    if(vertex == graph.size() - 1) {
        ans.push_back(path) ;
        return ;
    }
    visited[vertex] = true ;
    for( auto child : graph[vertex]) {
        if(child == parent) continue ;
        if(visited[parent]) continue;
        path.push_back(child) ;
        cout << child << " " << vertex << endl  ;
        findPath(child, vertex, graph, ans, path) ;
        path.pop_back() ;
    }
}

int main() {
    int n ;
    cin >> n ;

    unordered_map<int,unordered_set<int>> graph ;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x ;
            cin >> x ;
            if (x) {
                graph[i].insert(j) ;
                graph[j].insert(i) ;
            }
        }
        
    }

    vector<vector<int>> ans ;

    vector<int> path ;
    path.push_back(0) ;

    // findPath(0, 0, graph, ans, path) ;

    // for( auto & it : ans ) {
    //     for (int & i : it) {
    //         cout << i << " " ;
    //     }
    //     cout << endl ;
    // }
    // cout << endl ;
    for(auto & pr : graph) {
        cout << pr.first << " : " ;
        for(int i : pr.second) {
            cout << i << " " ;
        }
        cout << endl ;
    }
    
    return 0 ;
}

/*
void genPaths(vector<int> arr [], vector<string> & ans, vector<vector<int>> & path_hsh,string & path,  int i = 0 , int j = 0){
    if(i < 0 || j < 0 || i >= path_hsh.size() || j >= path_hsh[0].size() || arr[i][j] == 0) return ;
    if(i == path_hsh.size() - 1 && j == path_hsh.size() - 1) {
        ans.push_back(path) ;
        return ;
    }
    if(path_hsh[i][j] == 1) {
        return ;
    }
    path_hsh[i][j] = 1 ;

    // move up
    path.push_back('U') ;
    genPaths(arr, ans, path_hsh, path, i - 1, j) ;
    path.pop_back() ;

    // move left
    path.push_back('L') ;
    genPaths(arr, ans, path_hsh, path, i , j-1) ;
    path.pop_back() ;
    
    // move down
    path.push_back('D') ;
    genPaths(arr, ans, path_hsh, path, i + 1, j) ;
    path.pop_back() ;


    // move right
    path.push_back('R') ;
    genPaths(arr, ans, path_hsh, path, i , j+1) ;
    path.pop_back() ;

}

int main()
{
    int n ;
    cin >> n ;
    vector<int> maize[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x ;
            cin >> x ;
            maize[i].push_back(x) ;
        }
        
    }
    
    vector<string> ans ;
    vector<vector<int>> path(n,vector<int> (n,0)) ;
    string empty = "" ;
    genPaths(maize,ans,path, empty) ;

    for(auto it : path) {
        for(auto i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }

    for(auto it : ans){
        cout << it << endl ;
    }


    return 0 ;
}
*/