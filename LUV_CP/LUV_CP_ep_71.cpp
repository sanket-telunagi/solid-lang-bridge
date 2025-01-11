/*
    Using DFS - 
        1. Finding connected components 
            - Loop through each vetex where dfs on vertex will mark all connected vetices 
            - Now count loop ran

        2. Detectng loop
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// ------ to fing no of components 
void DFS (int vertex ,vector<bool> & visited, unordered_map<int,vector<int>> & graph){
    visited[vertex] = true ;
    for(int child : graph[vertex]) {
        if(visited[child]) continue;
        DFS(child, visited, graph) ;
    }
    cout << endl ;
}

// ---- To find all the coponents 
void DFS (int vertex, vector<int> & component,vector<bool> & visited, unordered_map<int,vector<int>> & graph){
    visited[vertex] = true ;
    component.push_back(vertex) ;
    for(int child : graph[vertex]) {
        if(visited[child]) continue;
        DFS(child,component, visited, graph) ;
    }
    cout << endl ;
}

// To detect loop 
/*
    return true if the given graph contains loop
    it can be searched by finding if the given vertex is visited (except parent)
*/
bool DFS (int vertex,int parent , vector<bool> & visited, unordered_map<int,vector<int>> & graph) {
    visited[vertex] = true ;
    bool isLoopDetected = false ;
    for(int child : graph[vertex]){
        if (visited[child] && child == parent) continue;
        if (visited[child]) return true ;

        isLoopDetected |= DFS(child,vertex, visited, graph) ;
    }
    return isLoopDetected ;
}


void print(unordered_map<int,vector<int>> & graph) {
    for(auto & pr : graph) {
        std :: cout << pr.first << " : "  ;
        for (auto & it : pr.second) {
            std :: cout << it << " " ;
        }
        std :: cout << endl ;
    }
}

void print(vector<bool> & visited) {
    for(auto i : visited) {
        std :: cout << i << " " ;
    }
    std :: cout << endl ;
}

void print(vector<vector<int>> & arr) {
    for(vector<int> & it : arr){
        for(int & i : it) {
            cout << i << " " ;
        }
        cout << endl ;
    }
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    unordered_map<int,vector<int>> graph ;
    vector<bool> visited(n,false) ;
    vector<vector<int>> components ;
    for (int i = 0; i < m; i++)
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        graph[v1].push_back(v2) ;
        // graph[v2].push_back(v1) ;
    }


    // ----  count of connected component
    // int ct = 0 ;
    // for (int i = 1; i <= n; i++)
    // {
    //     if(visited[i]) continue;
    //     DFS(i,visited, graph) ;
    //     ct++ ;
    // }
    // std :: cout << ct << endl ;

    // ---- All connected components
    // for (int i = 1; i <= n; i++)
    // {
    //     if(visited[i]) continue;
    //     vector<int> component ;
    //     DFS(i,component,visited,graph) ;
    //     components.push_back(component) ;
    // }
    // No of components 
    // cout << components.size() << endl ;
    // print(components) ;


    // ----- detecting loop in the component
    bool isLoopDetected = false ;
    for (int i = 1; i <= n; i++)
    {
        if(visited[i]) continue;
        if(DFS(i,0,visited,graph)) {
            isLoopDetected = true ;
            break;
        }
    }
    cout << isLoopDetected << endl ;
    return 0 ;
}