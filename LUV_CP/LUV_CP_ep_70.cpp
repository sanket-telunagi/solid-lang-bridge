/*
    Travarsal of Graph 
        1. Depth First search (DFS)
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void DFS (int vertex, vector<bool> & visited, unordered_map<int,vector<int>> & graph) {
    /*
        sec 1 : Take action on vertex after entering the vertex
    */

    visited[vertex] = true ;
    cout << vertex << endl ;
    for(int child : graph[vertex]) {
        /*
            sec 2 : Take action on child before entering the child node
        */
        cout << "par " << vertex << " Child " << child << " " << visited[child] << endl ;
        if(visited[child]) continue;

        DFS(child, visited, graph) ;

        /*
            sec 3 : Take action on child after exiting the child node 
        */
    }
    /*
        sec 4 : Take action on vetex after exiting the vertex
    */
}

int main()
{
    
    int n , m ;
    cin >> n >> m ;
    // vector<vector<int>> graph(n+1) ;
    unordered_map<int,vector<int>> graph ;
    vector<bool> visited(n+1,false) ;

    while (m--)     
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        graph[v1].push_back(v2) ;
        graph[v2].push_back(v1) ;
    }
    for(auto & pr : graph) {
        cout << pr.first << " : "  ;
        for (auto & it : pr.second) {
            cout << it << " " ;
        }
        cout << endl ;
    }
    
    cout << endl ;
    DFS(1,visited , graph) ;
    
    return 0 ;
}