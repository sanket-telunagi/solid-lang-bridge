/*
    Que - 

        Given an undirected tree with N nodes labeled from 1 to N.
        Each node has a certain weight assigned to it given by an integer array A of size N.
        You need to delete an edge in such a way that the Product between the sum of 
        weights of nodes in one subtree with the sum of weights of nodes in other subtree is maximized.
        Return this maximum possible product modulo 109 + 7.

        NOTE:

        The tree is rooted at a node labeled with 1.
        You need to return the maximum possible product, then take its mod.

    Approach - 
        - Run a DFS for precomuting the sum of each subtree
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

// DFS
void DFS(vector<vector<int>> & edges, vector<int> & values, vector<int> & subtree_sum, int vertex = 1, int par = 1) {

    subtree_sum[vertex] = values[vertex] ;

    for(int & child : edges[vertex]) {
        if (child == par) continue;
        DFS(edges, values, subtree_sum, child, vertex) ;

        subtree_sum[vertex] += subtree_sum[child] ; 
    }
}

// each node will try to delete the edge above it and thus the ans will maximised
int delete_edge(vector<int> & subtree_sum, int nodes) {

    int ans = 0 ;
    for (int i = 2; i < nodes; i++)
    {
        // suppose sum1 edge 1 is deleted the remaining tree sum is calculated 

        int sum1 = subtree_sum[i] ;
        int sum2 = subtree_sum[1] - sum1 ;

        // maximise the product
        ans = max(ans , sum1 * sum2) ;
    }
    return ans ;
}

int main()
{
    int n ; // nodes 
    cin >> n ;

    // values at each node root at 1
    vector<int> vals (n + 1) ;
    for (int i = 1; i < n+1; i++) cin >> vals[i] ;

    // edges of graph 
    vector<vector<int>> edges(n+1) ;
    for (int i = 0; i < n-1; i++)
    {
        int v1 , v2 ;
        cin >> v1 >> v2 ;
        edges[v1].push_back(v2) ;
        edges[v2].push_back(v1) ;
    }

    vector<int> subtree_sum (n+1, 0) ; // store the sum of subtree from each node

    // DFS call 
    DFS(edges, vals, subtree_sum) ;

    // for (auto i : subtree_sum) cout << i << " " ;

    // function call nodes are from 1
    cout << delete_edge(subtree_sum, n+1) <<endl ;
    
    return 0 ;
}