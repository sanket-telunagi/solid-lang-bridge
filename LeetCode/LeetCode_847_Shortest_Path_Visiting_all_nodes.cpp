#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

void BFS(vector<vector<int>> & graph, vector<bool> & visited, int & ans) {
    queue <int> q ;
    q.push(0) ;

    while (!q.empty())
    {
        int curr_node = q.front() ;
        q.pop() ;
        visited[curr_node] = true ;
        for(auto & child : graph[curr_node]) {
            if (!visited[child]) {
                ans++ ;
                q.push(child) ;
            }
        }
    }

}

int shortestPathLength(vector<vector<int>>& graph) {
    int ans = 0 ;
    vector<bool> visited(graph.size()) ;
    BFS(graph, visited, ans) ;
    return ans ;
}

int main()
{
    // nodes
    int n ;
    cin >> n ;

    // graph 
    vector<vector<int>> graph(n) ;
    for (int i = 0; i < n; i++)
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        graph[v1].push_back(v2) ;
        graph[v2].push_back(v1) ;
    }

    // visited bool 
    vector<bool> vis(n) ;

    cout << shortestPathLength(graph) << endl; 
    return 0 ;
}