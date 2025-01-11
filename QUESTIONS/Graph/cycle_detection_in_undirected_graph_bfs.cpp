#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// return true if raph contains loop 




bool bfs(int src, int * vis, vector<int>  adj[]) {
    // int n= adj.size() ;

    // store the node and its parent 
    queue<pair<int,int>> q ;
    q.push({src, -1}) ; // first node has parent -1 

    while (!q.empty()) {
        int node = q.front().first ; // get the node 
        int par = q.front().second ; // get the parent 
        q.pop() ;
        vis[node] = true ; // visited node

        for (auto child : adj[node]) {
            if (!vis[child]) {
                vis[child] = true ;
                q.push({child, node}) ; // child will be new node and previous node will be parent 
            } 
            else if (par != child) return true ; // there is visited node not a parent with shows it is looped
        }
    }
    return false ;
}

bool detectCycle(int n, vector<int> adj[]) {
    // create an visited array 
    int vis[n + 1] = {0} ;

    // run bfs for all nodes 
    for (int i = 0 ; i < n ; i++) {
        if ( !vis[i] and bfs(i, vis, adj) ) {
            return true ;
        }
    }
    return false ;
}

int main()
{
    int n , m ;
    cin >> n >> m ;
    vector<int> adj[n] ; // total of n nodes
    for (int i = 0; i < m; i++)
    {
        int x, y ;
        cin >>x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " : " ;
        for(auto j : adj[i]) {
            cout << j << " " ;
        }
        cout << endl ;
    }

    // cout << detectCycle(m, adj) ;

    
    return 0 ;
}