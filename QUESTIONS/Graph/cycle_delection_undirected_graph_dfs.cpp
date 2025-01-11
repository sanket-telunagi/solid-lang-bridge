#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool dfs (int node, int par, int * vis, vector<int> adj[]) {
    vis[node] = 1 ; // mark the node visited 
    bool ans = false ;
    for (auto child : adj[node]) {
        if (!vis[child]) { // traverse through all the child 
            ans |= dfs(child, node, vis, adj) ; // make the node as paraent of child and dfs
        }
        else if (child != par) return true  ; // id node is visited and its not teh parent then loop exists 
    }

    return ans ; 
}

bool detectCycle(int n, vector<int> adj[]) {
    int vis[n+1] = {0} ;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && dfs(i, -1, vis, adj)) {
            return true ;
        }
    }

    return false ;
    
    
}

int main()
{
    int n, m ;
    cin >> n >> m;
    vector<int> adj[n] ;
    for (int i = 0; i < m; i++)
    {
        int x , y ;
        cin >> x >> y ;
        adj[x].push_back(y) ;
        adj[y].push_back(x) ;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " : " ;
    //     for(auto j : adj[i]) {
    //         cout << j << " " ;
    //     }
    //     cout << endl ;
    // }
    

    cout << detectCycle(n, adj) << endl ;
    
    return 0 ;
}